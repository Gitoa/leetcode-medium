class Solution {
public:
    int computeAreaOne(int A, int B, int C, int D, int E, int F, int G, int H){
        if(G<=C){
            if(F>=D){
                return 0;
            }else if(H>=D && F<=D && F>=B){
                return (G-E)*(D-F);
            }else if(H>=D && F<=B){
                return (G-E)*(D-B);
            }else if(H<=D && F>=B){
                return (H-F)*(G-E);
            }else if(H>=B && F<=B){
                return (H-B)*(G-E);
            }else{
                return 0;
            }
        }else if(E>=C){
            return 0;
        }else{
            if(F>=D){
                return 0;
            }else if(H>=D && F<=D && F>=B){
                return (C-E)*(D-F);
            }else if(H>=D && F<=B){
                return (C-E)*(D-B);
            }else if(H<=D && F>=B){
                return (C-E)*(H-F);
            }else if(H>=B && F<=B){
                return (C-E)*(H-B);
            }else{
                return 0;
            }
        }
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int shareArea;
        if(A<=E){
            shareArea=computeAreaOne(A, B, C, D, E, F, G, H);
        }else{
            shareArea=computeAreaOne(E, F, G, H, A, B, C, D);
        }
        return (D-B)*(C-A) + (H-F)*(G-E) - shareArea;
    }
};