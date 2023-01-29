
/// CodeStudio Code  (Beautiful String)


int makeBeautiful(string str) {
	int i=0, j=0;
	for(int k=0;k<str.size();k++){
		if((k%2==0 and str[k]!='1') or (k%2!=0 and str[k]!='0')) i++;
		if((k%2==0 and str[k]!='0') or (k%2!=0 and str[k]!='1')) j++;
	}
	return min(i,j);
}

