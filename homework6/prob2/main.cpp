#include"lotterystation.hpp"

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6};
    int b[8] = {3, 4, 5, 6, 7, 8, 10, 11};
    CustomSet<int> foo1(a, 6);
    CustomSet<int> foo2(b, 8);
    LotteryStation sample;
    sample.newRound();
    sample.setPrizeNumbers(foo1, LOTTO6);
    LotteryTicket* jackpot = sample.buy(foo2, LOTTO6);
    // prints "Bought a Lotto 6 ticket for 2 Yuan at round 1.\n"
    sample.claimPrize(jackpot);
    // prints "This ticket wins 2000000 Yuan.\n"
    delete jackpot;
}