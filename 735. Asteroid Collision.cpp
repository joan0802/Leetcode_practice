class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> col; // store the not collided asteroids
        for(auto ast: asteroids) {
            if(col.empty()) {
                col.push_back(ast);
            }
            else if(col.back() > 0 && ast < 0) { // collide
                if(col.back() < abs(ast)) {
                    while(!col.empty() && col.back() > 0 && abs(col.back()) < abs(ast)) {
                        col.pop_back();
                    }
                    if (col.empty() || col.back() < 0) {
                        col.push_back(ast);
                    } 
                    else if (col.back() == abs(ast)) {
                        col.pop_back();
                    }
                    // else ast < col, ast explode
                }
                else if(abs(col.back()) == abs(ast))
                    col.pop_back();
                // else -> ast is smaller than the asteroids, collide and disappear
            }
            else { // same direction
                col.push_back(ast);
            }
        }
        return col;
    }
};
