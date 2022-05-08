class Solution {
    string chars =  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> map;
    string hashCode =getRand();
    string tinyurl = "http://tinyurl.com/";
    int codelength = 6;

public:
    string hashing(string longUrl){
        string sb = "";
        while(codelength > 0){
            sb = chars[codelength%62] + sb;
            codelength--;
        }
        if(map.find(sb) != map.end()){
            return hashing(longUrl);
        }else{
            map[sb] = longUrl;
            return sb;
        }
    }
    string encode(string longUrl) {
        hashCode = hashing(longUrl);
        return  tinyurl + hashCode;
    }
    string decode(string shortUrl) {
        string hashCode = shortUrl.substr(shortUrl.size()-codelength);
        return map[hashCode];
    }

};