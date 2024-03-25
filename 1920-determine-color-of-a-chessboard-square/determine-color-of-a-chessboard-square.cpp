class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char c=coordinates[0], d=coordinates[1];
        if(c=='a'||c=='c'||c=='e'||c=='g'){
            if(d%2==1) return false;
            else return true;
        } else{
            if(d%2==0) return false;
            else true;
        }
        return true;
    }
};