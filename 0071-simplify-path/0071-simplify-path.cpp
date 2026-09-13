class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int start = 0;
        int dotcount = 0;

        for (int i = 0; i < path.size(); i++)
        {
            if (start == 0 && path[i] == '/')
            {
                start = 1;
            }

            // multiple slash skip
            if (path[i] == '/')
            {
                if (ans.empty() || ans.back() != '/')
                    ans += '/';

                continue;
            }

            // count dots
            int dotStart = i;

            while (i < path.size() && path[i] == '.')
            {
                dotcount++;
                i++;
            }

            bool segmentEnded =
                (i >= path.size() || path[i] == '/');

            // "."
            if (dotcount == 1 && segmentEnded)
            {
                dotcount = 0;
                i--;
                continue;
            }

            // ".."
            else if (dotcount == 2 && segmentEnded)
            {
                if (ans.size() > 1 && ans.back() == '/')
                    ans.pop_back();

                int pos = ans.find_last_of('/');

                if (pos == string::npos)
                    ans = "";
                else if (pos == 0)
                    ans = "/";
                else
                    ans.erase(pos + 1);

                dotcount = 0;
                i--;
                continue;
            }

            // "...", "..hidden", ".abc", etc.
            else if (dotcount > 0)
            {
                for (int j = 0; j < dotcount; j++)
                    ans += '.';

                dotcount = 0;
            }

            // remaining current segment
            while (i < path.size() && path[i] != '/')
            {
                ans += path[i];
                i++;
            }

            i--;

            if (i + 1 < path.size() && path[i + 1] == '/')
            {
                if (ans.empty() || ans.back() != '/')
                    ans += '/';
            }
        }

        // remove trailing slash
        if (ans.size() > 1 && ans.back() == '/')
            ans.pop_back();

        if (ans.empty())
            return "/";

        return ans;
    }
};