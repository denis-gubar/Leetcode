class AuctionSystem {
public:
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        removeBid(userId, itemId);
        BidByItemId[itemId][userId] = bidAmount;
        Bids[itemId].insert({ bidAmount, userId });
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        removeBid(userId, itemId);
        addBid(userId, itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        if (auto it = BidByItemId.find(itemId); it == BidByItemId.end())
            return;
        if (auto it = BidByItemId[itemId].find(userId); it != BidByItemId[itemId].end())
        {
            Bids[itemId].erase({ it->second, it->first });
            BidByItemId[itemId].erase(it);
        }
    }
    
    int getHighestBidder(int itemId) {
        if (auto it = Bids.find(itemId); it == Bids.end() || it->second.empty())
            return -1;
        else
            return it->second.rbegin()->second;
    }
    //ItemId, UserId, Amount
    unordered_map<int, unordered_map<int, int>> BidByItemId;
    //ItemId, Amount, UserId
    unordered_map<int, set<pair<int, int>>> Bids;
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
