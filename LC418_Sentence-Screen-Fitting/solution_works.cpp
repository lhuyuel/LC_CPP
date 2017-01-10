    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // cat all the words
        string str = "";
        for (const string &word : sentence)
            str += word + " ";
            
        int strLen = str.length();
        int start = 0;
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (str[start%strLen] == ' ')
                ++start; // skip the space
            else {
                // find the first space
                while (start >= 0 && str[start%strLen] != ' ') --start;
                start += 1; // skip the space
            }
        }
        return start / strLen;
    }
