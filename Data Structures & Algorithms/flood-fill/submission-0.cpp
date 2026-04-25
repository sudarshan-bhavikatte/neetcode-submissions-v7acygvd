class Solution {
    int ROWS;
    int COLS;
    int color;
    int original;
    vector<vector<int>> V;
    void dfs(vector<vector<int>>& image, int r, int c){

        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || V[r][c] == 1 || image[r][c] != original)return;


        image[r][c] = color;
        V[r][c] = 1;

        dfs(image, r, c+1);
        dfs(image, r+1, c);
        dfs(image, r, c-1);
        dfs(image, r-1, c);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ROWS = image.size();
        COLS = image[0].size();
        this->color = color;
        this->original = image[sr][sc];

        V.assign(ROWS, vector<int>(COLS,0));
        dfs(image, sr, sc);

        return image;
    }
};