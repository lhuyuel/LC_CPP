/*

你有三台接啤酒的机器，分别是small，medium, large. 这三种size的机器按一次button一次分别能distribute, say 100 - 150ml, 200 - 250ml, 300 - 350ml的啤酒，每台机器出来的啤酒量是区间里的任意一个数不确定。说现在一个顾客自带一个“杯子“，这个杯子任意大小但是有两个限制 就是min和max volume意思就是 你最少要接到min(ml)在杯子里，最大能只能接max(ml)，然后你要想让顾客满意必须接在这个区间里面的那么多啤酒。比如说我有一个下限min是300ml 上限max是400ml, 那么我按一下small是接不够的， 我需要在按一下midium才能接够。但是有的时候我按midium可能也不行，比如说我midium的区间换成200 - 300ml, 那么我按一下small再按一下medium就可能接出（100 + 200）- （150 + 300）ml的酒，which is not valid cause (150 + 300 = 450) might exceed the max volume(400ml) of the cup。

*/



// DFS
bool getWine(vector<vector<int>> bottle,int wineMax, int wineMin, vector<int> path, vector<int>& result) {
    // treminate condition
    if (wineMax < wineMin || wineMin < bottle[0][0]) return false;
    
    
    for (int i = bottle.size(); i >= 0; --i) {
        path.push_back(i);
        // falls into a bottle range
        if (wineMin >= bottle[i][0] && wineMax <= bottle[i][1]) {
            return true;
        }
        
        bool isPossible = getWine(bottle, wineMax - bottle[i][1], wineMin - bottle[i][0], path, result);
        if (isPossible) return true;
        path.pop_back();
    }
    return false;
}
