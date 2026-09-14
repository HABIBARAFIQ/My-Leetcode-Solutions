class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr)
            return head;

        int pos = 1;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* nextnode = nullptr;

        unordered_map<ListNode*, int> mp;

        ListNode* targetnode = nullptr;
        ListNode* insertionnode = nullptr;

//       node >= x
        while (temp != nullptr)
        {
            mp[temp] = pos;

            if (targetnode == nullptr && temp->val >= x)
                targetnode = temp;

            pos++;
            temp = temp->next;
        }

        // if all node < x 
        if (targetnode == nullptr)
            return head;


        // 2. Find insertion point
        //    and detach < x nodes that appear after targetnode

        temp = head;
        prev = nullptr;

        while (temp != nullptr)
        {
            nextnode = temp->next;

            if (temp->val < x &&
                mp[temp] < mp[targetnode])
            {
                insertionnode = temp;
            }

            if (temp->val < x &&
                mp[temp] > mp[targetnode])
            {
                if (prev != nullptr)
                    prev->next = nextnode;

                temp->next = nullptr;
            }
            else
            {
                prev = temp;
            }

            temp = nextnode;
        }


        vector<pair<ListNode*, int>> v;

        for (auto p : mp)
        {
            v.push_back({p.first, p.second});
        }

        sort(v.begin(), v.end(),
            [](auto &a, auto &b)
            {
                return a.second < b.second;
            });

        if (insertionnode != nullptr)
        {
            ListNode* insert = insertionnode;

            for (auto p : v)
            {
                ListNode* node = p.first;
                int nodePos = p.second;

                if (node->val < x &&
                    nodePos > mp[targetnode])
                {
                    node->next = insert->next;
                    insert->next = node;

                    insert = node;
                }
            }
        }

        // special case:
        // শুরুতেই >=x ছিল
        else
        {
            ListNode* newHead = nullptr;
            ListNode* tail = nullptr;

            for (auto p : v)
            {
                ListNode* node = p.first;
                int nodePos = p.second;

                if (node->val < x &&
                    nodePos > mp[targetnode])
                {
                    if (newHead == nullptr)
                    {
                        newHead = node;
                        tail = node;
                    }
                    else
                    {
                        tail->next = node;
                        tail = node;
                    }
                }
            }

            if (newHead != nullptr)
            {
                tail->next = head;
                head = newHead;
            }
        }

        return head;
    }
};