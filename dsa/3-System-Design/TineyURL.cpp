// Design URL Shortening service like TinyURL

/*
We should check the following things::

What's the traffic volume / length of the shortened URL?
What's the mapping function?
Single machine or multiple machines?

Traffic: 
    Let's assume we want to serve more than 1000 billion URLs. If we can use 62 
characters [A-Z, a-z, 0-9] for the short URLs having length n, then we can have total
62^n URLs. So, we should keep our URLs as short as possible given that it should 
fulfill the requirement. For our requirement, we should use n=7 i.e the length of
short URLs will be 7 and we can serve 62^7 ~= 3500 billion URLs.


Multiple machines:

If we are dealing with massive data of our service, distributed storage can increase our capacity. The idea is simple, get a hash code from original URL and go to corresponding machine then use the same process as a single machine. For routing to the correct node in cluster, Consistent Hashing is commonly used.

Following is the pseudo code for example,

Get shortened URL

hash original URL string to 2 digits as hashed value hash_val

use hash_val to locate machine on the ring

insert original URL into the database and use getShortURL function to get shortened URL short_url

Combine hash_val and short_url as our final_short_url (length=8) and return to the user

Retrieve original from short URL

get first two chars in final_short_url as hash_val

use hash_val to locate the machine

find the row in the table by rest of 6 chars in final_short_url as short_url

return original_url to the user
*/

string idToShortURL(long long int n) {
    
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                 "GHIJKLMNOPQRSTUVWXYZ0123456789";

    string shortURL = "";

    while(n){
        shortURL.push_back(map[n%62]);
        n /= 62;
    }
    reverse(shortURL.begin(), shortURL.end());
    return shortURL;
}
long int shortURLToID(string shortURL) {
    long int id = 0;
    for(int i = 0; i < shortURL.size(); i++){
        if(shortURL[i] >= 'a' && shortURL[i] <= 'z'){
            id = id * 62 + shortURL[i] - 'a';
        }
        else if(shortURL[i] >= 'A' && shortURL[i] <= 'Z'){
            id = id * 62 + shortURL[i] - 'A';
        }
        else if(shortURL[i] >= '0' && shortURL[i] <= '9'){
            id = id * 62 + shortURL[i] - '0';
        }
    } 
    return id;  
}


class Solution {
private:
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> longToShort, shortToLong;
public:
    
    // "http://tinyurl.com/" is 19 char long 
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrlCode = "";
        if(longToShort.find(longUrl) == longToShort.end()){
            
            // if shortUrlCode generated is duplicate, regenerate it
            do{
                for(int i = 0; i < 6; ++i){
                    int idx = rand()%charset.size();
                    shortUrlCode += charset[idx];
                }
            } while (shortToLong.find(shortUrlCode) != shortToLong.end()) ;
            longToShort[longUrl] = shortUrlCode;
            shortToLong[shortUrlCode] = longUrl;
        }
        else{
            shortUrlCode = longToShort[longUrl];
        }
        return "http://tinyurl.com/" + shortUrlCode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size() != 25) return "";
        string shortUrlCode = shortUrl.substr(19, 6);
        if(shortToLong.find(shortUrlCode) == shortToLong.end()){
            return ""; // innvalid url
        }
        return shortToLong[shortUrlCode];
    }
};



// Short
class Solution {
    unordered_map<int,string> urlsdb;
    int i=0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urlsdb[i] = longUrl;
        return "http://tinyurl.com/"+ to_string(i++); 
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlsdb[stoi(shortUrl.replace(0,19, ""))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));