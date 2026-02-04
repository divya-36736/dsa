class RideSharingSystem {
public:
    queue<int>rider, driver;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(!rider.empty() && !driver.empty()){
            int rid1  = rider.front();
            rider.pop();
            int dri1 = driver.front();
            driver.pop();
            return {dri1, rid1};
        }
        else{
            return {-1, -1};
        }
    }
    
    void cancelRider(int riderId) {
        queue<int>temp; 
        while(!rider.empty()){
            int rid1  = rider.front();
            rider.pop();
            if(rid1 != riderId){
                temp.push(rid1);
            }
        }
        rider = temp;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */