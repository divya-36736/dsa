class Robot {
public:
    int x = 0, y = 0;
    int wid, h;
    int dir = 0; 

    Robot(int width, int height) {
        wid = width;
        h = height;
    }

    void step(int num) {
        int perimeter = 2 * (wid + h - 2);
        num %= perimeter;

        
        if (num == 0 && (x != 0 || y != 0)) {
            num = perimeter;
        }

        if (num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }

        while (num--) {
            if (dir == 0) { 
                if (x + 1 < wid) x++;
                else {
                    dir = 1;
                    y++;
                }
            }
            else if (dir == 1) { 
                if (y + 1 < h) y++;
                else {
                    dir = 2;
                    x--;
                }
            }
            else if (dir == 2) { 
                if (x - 1 >= 0) x--;
                else {
                    dir = 3;
                    y--;
                }
            }
            else { 
                if (y - 1 >= 0) y--;
                else {
                    dir = 0;
                    x++;
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};