bool ZSearch(const string & P, const string & T){
	string concat = P + "$" + T;
	int l = concat.size();
	vector<int> Z(l, -1);
	int left = 0, right = 0;
	
	for(int i = 0; i < l; i++){
		if(i > left){
			left=right=i;
			while(right<l&&concat[right]==concat[right-left])
				right++;
			Z[i]=right-left;
			right++;
		}else if(Z[i-left]<right-i+1){
			Z[i]=Z[i-left];
		}else{
			left=i;
			while(right<l&&concat[right]==concat[right-left])
				right++;
			Z[i]=right-left;
			right++;
		}
	}
	
	for(int i=0; i<l; i++){
		if (Z[i]==P.size()) return true;
	}
	
	return false;
}