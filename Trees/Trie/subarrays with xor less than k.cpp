


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
  	Node *left,*right;
    ll leaf_cnt;
    Node()
    {
        left=right=NULL;
        leaf_cnt=0;
    }
};
void insert(Node *root,ll val)
{
	Node *cur=root;
    for(ll i=31;i>=0;i--)
    {
        ll bitVal=(1<<i)&(val);
        if(bitVal==0)
        {
            if(!cur->left)
            {
                cur->left=new Node();
            }
            cur=cur->left;
        }else{
            if(!cur->right)
            {
                cur->right=new Node();
            }
            cur=cur->right;
        }
        cur->leaf_cnt++;
    }
}
ll findCnt(Node *root,ll cur_xor,ll k)
{
    ll cnt=0;
    Node *cur=root;
    for(ll i=31;i>=0;i--)
    {
        ll p1=(cur_xor>>i)&(1);
        ll k1=(k>>i)&(1);
        if(p1==1&&(k1==1))
        {
            if(cur->right)
            {
                cnt+=(cur->right->leaf_cnt);
            }
            if(cur->left)
            {
                cur=cur->left;
            }else{
                break;
            }
        }else if(p1==0&&(k1==1))
        {
            if(cur->left)
            {
                cnt+=(cur->left->leaf_cnt);
            }
            if(cur->right)
            {
                cur=cur->right;
            }else{
                break;
            }
        }else if(p1==0&&(k1==0))
        {
            if(cur->left)
            {
                cur=cur->left;
            }else{
                break;
            }
        }else if(p1==1&&(k1==0))
        {
            if(cur->right)
            {
                cur=cur->right;
            }else{
                break;
            }
        }
    }
    return cnt;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        Node *root=new Node();
        ll cnt=0;
        ll cur_xor=a[0];
        if(cur_xor<k)
        {
            cnt++;
        }
        insert(root,cur_xor);
        for(ll i=1;i<n;i++)
        {
            cur_xor=(cur_xor)^(a[i]);
            if(cur_xor<k)
            {
                cnt++;
            }
            cnt+=(findCnt(root,cur_xor,k));
            insert(root,cur_xor);
        }
        cout<<cnt<<endl;
    }
    return 0;
}


















#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	Node *left,*right;
	ll leaf_cnt;
	Node()
	{
		left=right=NULL;
		leaf_cnt=0;
	}
};
void insert(Node *root,ll val)
{
	Node *cur=root;
	for(ll i=31;i>=0;i--)
	{
        ll temp=((1<<i)&val);
		if(temp==0)
		{
			if(!cur->left)
			{
				cur->left=new Node();
			}
			cur=cur->left;
            cur->leaf_cnt++;
		}else{
			if(!cur->right)
			{
				cur->right=new Node();
			}
			cur=cur->right;
			cur->leaf_cnt++;
		}
	}
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		Node *root=new Node();
		ll n,k;
		cin>>n>>k;
		ll *a=new ll[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll ans=0;
		ll cur_xor=a[0];
		if(cur_xor<k)
		{
			ans++;
		}
		insert(root,cur_xor);
		for(ll i=1;i<n;i++)
		{
			cur_xor=(cur_xor)^(a[i]);
			if(cur_xor<k)
			{
				ans++;
			}
            Node *cur_node=root;
			for(ll j=31;j>=0;j--)
			{
                ll k_bit=((k>>j)&1);
                ll p_bit=((cur_xor>>j)&1);
				if((p_bit==0)&&(k_bit==1))
				{
					if(cur_node->left)
					{
						ans+=(cur_node->left->leaf_cnt);
					}
					if(cur_node->right)
					{
						cur_node=cur_node->right;
					}else{
						break;
					}
				}else if((p_bit==1)&&(k_bit==1))
				{
					if(cur_node->right)
					{
						ans+=(cur_node->right->leaf_cnt);
					}
					if(cur_node->left)
					{
						cur_node=cur_node->left;
					}else{
						break;
					}
				}else if((p_bit==0)&&(k_bit==0))
				{
					if(cur_node->left)
					{
						cur_node=cur_node->left;
					}else{
						break;
					}
				}else if((p_bit==1)&&(k_bit==0))
				{
					if(cur_node->right)
					{
						cur_node=cur_node->right;
					}else{
						break;
					}
				}
			}
			insert(root,cur_xor);
		}
		cout<<ans<<endl;
	}
}











