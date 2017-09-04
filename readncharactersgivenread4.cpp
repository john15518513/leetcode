// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        char buf4[4];
        int index = 0;
        while(true) {
            cnt = read4(buf4);
            if (cnt == 0) break;
            for (int i = 0; i < cnt and n > 0; i++) {
                buf[index++] = buf4[i];
                n--;
            }
        }
        return index;
    }
};
