//
//  test.cpp
//  leetcode
//
//  Created by Candy on 4/4/15.
//  Copyright (c) 2015 Hui. All rights reserved.
//

#include "test.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <stdio.h>
#include <map>
#include <queue>
using namespace std;
struct Module{
    int signal;
    int num;
    vector<int> generate;
    Module(int s,vector<int> g):signal(s),generate(g),num(0) {}
};
void handle(vector<int> &initial,map<int,Module*> &sigModule) {
    for(int i=0;i<initial.size();++i) {
        queue<int> snl;
        snl.push(initial[i]);
        while(!snl.empty()) {
            int tt=snl.front();
            snl.pop();
            Module *temp=sigModule[tt];
            
            ++(temp->num);
            
            if(!(temp->generate).empty()) {
                for(int s:temp->generate) {
                    std::cout<<s;
                    snl.push(s);
                }
            }
        }
    }
}
//int main(int argc, char const *argv[])
//{
//    int num=0;
//    cin>>num;
//    if(num<=0) return 0;
//    int N,M;
//    
//    map<int,Module*> sigModule; //signal,module;
//    vector<vector<int>> signal;
//    vector<vector<int>> initial;
//    for(int k=0;k<num;++k) {
//        scanf("%d %d",&N,&M);
//        vector<int> in;
//        vector<int> sig;
//        for(int i=0;i<M;++i) {
//            int temp=0;
//            cin>>temp;
//            in.push_back(temp);
//        }
//        initial.push_back(in);
//        for(int i=0;i<N;++i) {
//            int temp,num;
//            vector<int> vec;
//            cin>>temp>>num;
//            sig.push_back(temp);
//            // std::cout<<temp<<" "<<num<<std::endl;
//            for(int j=0;j<num;++j) {
//                int sig;
//                cin>>sig;
//                vec.push_back(sig);
//            }
//            // for(auto i:vec) {
//            // 	std::cout<<i<<std::endl;
//            // }
//            Module *mo=new Module(temp,vec);
//            sigModule[temp]=mo;
//        }
//        signal.push_back(sig);
//    }
//    for(int i=0;i<num;++i) {
//        handle(initial[i],sigModule);
//        for(int j=0;j<signal[i].size();++j) {
//            // std::cout<<signal[i]<<std::endl;
//            std::cout<<sigModule[signal[i][j]]->num<<" ";
//            // for(auto g:sigModule[signal[i]]->generate) {
//            // 	std::cout<<g<<" ";
//            // }
//        }
//    }
//    std::cout<<endl;
//    return 0;
//}