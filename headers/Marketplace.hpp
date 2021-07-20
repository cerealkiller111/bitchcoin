#include <vector>
#include <memory>
#ifndef Marketplace_H
    #define Marketplace_H
#endif



class Node;



class Stall
{
    public:
        std::shared_ptr<Node> seller;
        double amount; // <double> amount of bitcoins/money to sell
        bool type;     // whether = 0 (selling bitcoins for money) / 1 (selling money for bitcoins)

    // contructor
    Stall(std::shared_ptr<Node>& s, bool& t, double& a);

    // destructor
    ~Stall();

}; typedef struct Stall Stall;



class Marketplace
{
    public:
        std::vector<std::shared_ptr<Stall>> market;
        /* 
        Each trader who wanna trade will open a stall, so that other nodes can visit and perform the trade.
        Once the trade between the stall owner and the visittor is completed, the stall will be force to close
        
        Note : the process of creating-deleting Stall objects are done manually 100%, 
        so we don't need to use unique_ptr to make stuffs more complex
        */

        // constructor
        Marketplace();

        // destructor
        ~Marketplace();

        // methods
        void openStall(std::shared_ptr<Node>& s, bool& t, double& a);

        void closeStall();

        void showAllStalls();

};
