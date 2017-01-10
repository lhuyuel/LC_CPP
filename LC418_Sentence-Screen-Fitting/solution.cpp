    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int count = 0; // count times
        int curRow = 0, startPoint = 0;
        while (curRow <= rows) {
            int i = 0;
            while (i < sentence.size()) {
                // if a single word length is larget then screen width, there is no way to fit
                if (sentence[i].length() > cols) return 0;
                
                if (startPoint + sentence[i].length() <= cols) {
                    startPoint += sentence[i].length() + 1; // update startPoint, '1' for the space
                    ++i;
                }
                else {
                    // have spare rows, go to next row
                    if (curRow < rows - 1) {
                        startPoint = 0;
                        ++curRow;
                    }
                    else {
                        ++curRow; // to break the outer loop
                        break;
                    }
                }
            }
            
            // if all the words has been printed on the screen
            if (i == sentence.size())
                ++count;
        }
        return count;
    }
