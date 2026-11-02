class Codec {
public:
    string serialize(TreeNode* root) {
        vector<string> res;
        dfs(root, res);
        return join(res, ",");
    }

    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfs(vals, i);
    }

private:
    void dfs(TreeNode* node, vector<string>& res) {
        if (!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfs(node->left, res);
        dfs(node->right, res);
    }

    TreeNode* dfs(vector<string>& vals, int& i) {
        if (vals[i] == "N") {
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfs(vals, i);
        node->right = dfs(vals, i);
        return node;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (size_t k = 0; k < v.size(); ++k) {
            if (k > 0) {
                s << delim;
            }
            s << v[k];
        }
        return s.str();
    }
};