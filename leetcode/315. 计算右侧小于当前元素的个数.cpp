class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>count;//保存结果
        vector<pair<int,int> > num;//关联每个数和它的序号
        for(int i =0;i<nums.size();++i)
        {
            count.push_back(0);
            num.push_back(make_pair(nums[i],i));//保存每个数和它在原数组中的序号，以免在排序过程中打乱顺序
        }
        merge_sort(num,count);
        return count;
    }
    
    //归并排序
    void merge_sort(vector<pair<int,int> >& vec, vector<int>& count)
    {
        if(vec.size()<2)
            return;
        
        int mid = vec.size()/2;
        vector<pair<int,int> > sub_vec1;
        vector<pair<int,int> > sub_vec2;
        for(int i =0;i<mid;++i)
            sub_vec1.push_back(vec[i]);
        for(int i =mid;i< vec.size();++i)
            sub_vec2.push_back(vec[i]);
        
        merge_sort(sub_vec1,count);
        merge_sort(sub_vec2,count);
        vec.clear();
        merge(sub_vec1,sub_vec2,vec,count);
    }
    
    //合并两数组
    void merge(vector<pair<int,int> >& sub_vec1,vector<pair<int,int> >& sub_vec2, vector<pair<int,int> >& vec, vector<int>& count)
    {
        int i =0;
        int j =0;
        while(i < sub_vec1.size() && j < sub_vec2.size())
        {
            if(sub_vec1[i].first <= sub_vec2[j].first )
            {
                vec.push_back(sub_vec1[i]);
                count[sub_vec1[i].second] += j;//这句话和下面注释的地方就是这道题和归并排序的主要不同之处
                i++;
            }else{
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        
        for(;i<sub_vec1.size();++i)
        {
            vec.push_back(sub_vec1[i]);
            count[sub_vec1[i].second] += j;// -。-
        }
        for(;j<sub_vec2.size();++j)
        {
            vec.push_back(sub_vec2[j]);           
        }
    }
};