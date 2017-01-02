/*

An abbreviation of a word is <first letter><length -2 of the word><last letter>. Giving a dictionary and a word, find whether there is another word with same abbreviation in the dictionary. 

"internationalization" -> "i18n" 
"localization" -> "l10n" 
“dog” -> “d1g” 
“accessibility”, “automatically” -> “a11y” 

Input: dictionary, word 
Output: boolean: is the abbreviation of the word unique w.r.t. the dictionary?
*/

string getAbbr(string s) {
    return s[0] + to_string(s.length() - 2)+ s[s.length()-1];
}

unordered_map<string, int> table;
void preprocess(vector<string> dict) {
    for (string w : dict)
        ++table[getAbbr(w)];
}

bool isUniqueAbbr(string s) {
    if (table[getAbbr(s)] > 1) return true;
    return false;
}
