void mergesort(int a[], int l, int m, int h, int n) {
	int b[n], i=l, j=m+1, k=l;
	while(i<=m and j<=h) {
		if(a[i]<a[j]) b[k++]=a[i], i++;
		else b[k++]=a[j], j++;
	}
	for(int p=i;p<=m;p++) b[k++]=a[p];
	for(int p=j;p<=h;p++) b[k++]=a[p];
	for(int p=l;p<=h;p++) a[p]=b[p];
}
void merges(int a[], int l, int h, int n) {
	if(l>=h) return;
	int m=(l+h)/2;
	merges(a,l,m,n);
	merges(a,m+1,h,n);
	mergesort(a,l,m,h,n);
}
void quicksort(int a[], int l, int h) {
	if(l>=h) return;
	int i=l, j=h, t;
	int p=l;
	while(i<j) {
		while(a[i] <= a[p] and i<h) i++;
		while(a[j] > a[p]) j--;
		if(i < j) t=a[i], a[i]=a[j], a[j]=t;
	}
	t=a[p]; a[p]=a[j]; a[j]=t;
	quicksort(a,l,j-1);
	quicksort(a,j+1,h);
}
void bubblesort(int a[], int n) {
	for(int i=0;i<n-1;i++) for(int j=0;j<(n-i-1);j++) if(a[j] > a[j+1]) swap(a[j],a[j+1]);
}
void selectionsort(int a[], int n) { int t;	
	for(int i=0;i<n;i++) {
		int min=i;
		for(int j=i;j<n;j++) if(a[min] > a[j]) j=min;
		if(i!=min) t=a[i], a[i]=a[min], a[min]=t;
	}
}
void insertionsort(int a[], int n) {
	for(int i=1;i<n;i++) {
		int j=i-1;
		int x=a[i];
		while(j>=0 and x < a[j]) a[j+1]=a[j], j--;
		a[j+1]=x;
	}
}
