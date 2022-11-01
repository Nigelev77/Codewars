#include <iostream>
#include <string>
#include <vector>

#include <unordered_map>


#define STRINGIFY(name) #name

enum Events
{
    APP_PASSIVE_OPEN,
    APP_ACTIVE_OPEN,
    APP_SEND,
    APP_CLOSE,
    APP_TIMEOUT,
    RCV_SYN, 
    RCV_ACK,
    RCV_SYN_ACK,
    RCV_FIN,
    RCV_FIN_ACK
};

enum States
{
    CLOSED, LISTEN, SYN_SENT, SYN_RCVD, ESTABLISHED, CLOSE_WAIT, LAST_ACK, FIN_WAIT_1, FIN_WAIT_2, CLOSING, TIME_WAIT
};

std::vector<Events> events{APP_PASSIVE_OPEN, APP_ACTIVE_OPEN, APP_SEND, APP_CLOSE, APP_TIMEOUT, RCV_SYN, RCV_ACK, RCV_SYN_ACK, RCV_FIN, RCV_FIN_ACK};

std::unordered_map<std::pair<States, Events>, States> delta
{
    {{CLOSED, APP_PASSIVE_OPEN}, LISTEN},
    {{CLOSED, APP_ACTIVE_OPEN}, SYN_SENT},
    {{LISTEN, RCV_SYN}, SYN_RCVD},
    {{LISTEN, APP_SEND}, SYN_SENT},
    {{LISTEN, APP_CLOSE}, CLOSED},
    {{SYN_RCVD, APP_CLOSE}, FIN_WAIT_1},
    {{SYN_RCVD, RCV_ACK}, ESTABLISHED},
    {{SYN_SENT, RCV_SYN}, SYN_RCVD},
    {{SYN_SENT, RCV_SYN_ACK},   ESTABLISHED},
    {{SYN_SENT, APP_CLOSE},     CLOSED},
    {{ESTABLISHED, APP_CLOSE},  FIN_WAIT_1},
    {{ESTABLISHED, RCV_FIN},    CLOSE_WAIT},
    {{FIN_WAIT_1, RCV_FIN},     CLOSING},
    {{FIN_WAIT_1, RCV_FIN_ACK}, TIME_WAIT},
    {{FIN_WAIT_1, RCV_ACK},     FIN_WAIT_2},
    {{CLOSING, RCV_ACK},        TIME_WAIT},
    {{FIN_WAIT_2, RCV_FIN},     TIME_WAIT},
    {{TIME_WAIT, APP_TIMEOUT},  CLOSED},
    {{CLOSE_WAIT, APP_CLOSE},   LAST_ACK},
    {{LAST_ACK, RCV_ACK},       CLOSED}
};
std::unordered_map<std::string, Events> eventMap
{
    {STRINGIFY(APP_PASSIVE_OPEN), APP_PASSIVE_OPEN}, 
    {STRINGIFY(APP_ACTIVE_OPEN), APP_ACTIVE_OPEN},
    {STRINGIFY(APP_SEND), APP_SEND},
    {STRINGIFY(APP_CLOSE), APP_CLOSE},
    {STRINGIFY(APP_TIMEOUT), APP_TIMEOUT},
    {STRINGIFY(RCV_SYN), RCV_SYN}, 
    {STRINGIFY(RCV_ACK), RCV_ACK},
    {STRINGIFY(RCV_SYN_ACK), RCV_SYN_ACK},
    {STRINGIFY(RCV_FIN), RCV_FIN},
    {STRINGIFY(RCV_FIN_ACK), RCV_FIN_ACK}

};

std::unordered_map<std::string, States> stateMap
{
    {STRINGIFY(CLOSED), CLOSED}, 
    {STRINGIFY(LISTEN), LISTEN}, 
    {STRINGIFY(SYN_SENT), SYN_SENT}, 
    {STRINGIFY(SYN_RCVD), SYN_RCVD}, 
    {STRINGIFY(ESTABLISHED), ESTABLISHED}, 
    {STRINGIFY(CLOSE_WAIT), CLOSE_WAIT}, 
    {STRINGIFY(LAST_ACK), LAST_ACK}, 
    {STRINGIFY(FIN_WAIT_1), FIN_WAIT_1}, 
    {STRINGIFY(FIN_WAIT_2), FIN_WAIT_2}, 
    {STRINGIFY(CLOSING), CLOSING}, 
    {STRINGIFY(TIME_WAIT), TIME_WAIT}
};

std::string traverse_TCP_states(const std::vector<std::string>& events)
{
    States curState = CLOSED;
    for(auto& ev : events)
    {
        Events e = eventMap[ev];
        std::pair<Statts> input{curState, e};
        auto res = delta.find(input);
        if(res == delta.end()) return "ERROR";
        curState = res->second; 
    }
deldel

    std::string finalState;
    for(auto it = stateMap.begin(); it != stateMap.end(); it++)
    {
        if(it->second == curState)
        {
            return it->first;
        }
    }
    return "ERROR";
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

