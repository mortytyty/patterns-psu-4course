#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <list>
#include <stdexcept>
#include "parser.h"

class Command{
public:
    virtual ~Command(){};
    virtual void execute(std::string& str) = 0;
    virtual void undo(std::string& str) = 0;
};

class CustomCommand : public Command {
public:

    CustomCommand(const std::string& oper)
        :operand(oper){
    }

    CustomCommand(const double oper)
        :operand(std::to_string(oper)){
        this->TrimValue();
    }

    void execute(std::string& str) override{
        str.append(operand);
    }
    void undo(std::string& str) override{
        str.erase(str.length()-operand.length());
    }
private:
    std::string operand;

    void TrimValue(){
        size_t index = operand.find(".");
        if(index==std::string::npos)
            return;
        size_t last = operand.length()-1;
        size_t i;
        for(i = last;i>index;--i){
            if(operand[i]=='0')
                operand.pop_back();
        }
        if (i==index)
            operand.pop_back();
    }
};


class Invoker{
private:
    std::unordered_map <std::string,std::shared_ptr<Command>> lock_commands;
    std::vector <std::vector<std::shared_ptr<Command>>> switch_commands;
    std::list<std::shared_ptr<Command>> history;

    Parser parser_;
    bool continue_state_;
    int page_;

public:
    void SwitchtPage(){
        if(!page_){
            page_=1;
            return;
        }
        page_=0;
    }

    void ExecMainCommand(const std::string& command, std::string& str){
        if(!continue_state_)
            this->ClearAll(str);

        if(!lock_commands.count(command))
            return;

        lock_commands[command]->execute(str);
        history.push_back(lock_commands[command]);
    }

    void ExecSwitchCommand(unsigned index, std::string& str){
        if(!continue_state_)
            this->ClearAll(str);

        if(index>(switch_commands[page_].size()-1))
            return;
        switch_commands[page_][index]->execute(str);
        history.push_back(switch_commands[page_][index]);
    }

    void DeleteLast(std::string& str){
        if(history.empty())
            return;
        history.back()->undo(str);
        history.pop_back();
    }

    void ClearAll(std::string& str){
        history.clear();
        str.clear();
        continue_state_=true;
    }

    void Calculate(std::string& str){
        if(history.empty())
            return;

        try{
            auto parsed_str = parser_.parse(str);
            double result = parsed_str->evaluate();

            this->ClearAll(str);

            if(!result)
                continue_state_=false;

            history.push_back(std::make_shared<CustomCommand>(result));
            history.back()->execute(str);

        } catch(const std::runtime_error& ex){//

            this->ClearAll(str);
            history.push_back(std::make_shared<CustomCommand>("ERROR"));
            history.back()->execute(str);

            continue_state_=false;
        }
    }

    Invoker():page_(0)
    {
        lock_commands["+"]=std::make_shared<CustomCommand>("+");
        lock_commands["-"]=std::make_shared<CustomCommand>("-");
        lock_commands["*"]=std::make_shared<CustomCommand>("*");
        lock_commands["/"]=std::make_shared<CustomCommand>("/");
        lock_commands["."]=std::make_shared<CustomCommand>(".");

        lock_commands["1"]=std::make_shared<CustomCommand>("1");
        lock_commands["2"]=std::make_shared<CustomCommand>("2");
        lock_commands["3"]=std::make_shared<CustomCommand>("3");
        lock_commands["4"]=std::make_shared<CustomCommand>("4");
        lock_commands["5"]=std::make_shared<CustomCommand>("5");
        lock_commands["6"]=std::make_shared<CustomCommand>("6");
        lock_commands["7"]=std::make_shared<CustomCommand>("7");
        lock_commands["8"]=std::make_shared<CustomCommand>("8");
        lock_commands["9"]=std::make_shared<CustomCommand>("9");
        lock_commands["0"]=std::make_shared<CustomCommand>("0");

        switch_commands.resize(2);
        switch_commands[0].push_back(std::make_shared<CustomCommand>("("));
        switch_commands[0].push_back(std::make_shared<CustomCommand>(")"));
        switch_commands[0].push_back(std::make_shared<CustomCommand>("sqrt"));
        switch_commands[0].push_back(std::make_shared<CustomCommand>("^"));

        switch_commands[1].push_back(std::make_shared<CustomCommand>("sin"));
        switch_commands[1].push_back(std::make_shared<CustomCommand>("cos"));
        switch_commands[1].push_back(std::make_shared<CustomCommand>("tan"));
        switch_commands[1].push_back(std::make_shared<CustomCommand>("!"));
    }
};
