#include <stdio.h>
#include <stdlib.h>

struct agac{
	int data;
	struct agac * sag;
	struct agac * sol;
};
agac*root=NULL;
int rh=0;
int lh=0;
int toplam=0;
int temptoplam;
int t=0;

agac * ekle(agac * root, int deger){
	if(root==NULL){
		agac*root=(agac*)malloc(sizeof(agac));
		root->sol=NULL;
		root->sag=NULL;
		root->data=deger;
		return root;
	}
	if(deger > root->data){
		root->sag=ekle(root->sag, deger);
		return root;
	}
	root->sol=ekle(root->sol, deger);
	return root;
}

int max(agac*root){
	while(root->sag!=NULL){
		root=root->sag;
	}
	return root->data;
}

int min(agac*root){
	while(root->sol!=NULL)
		root=root->sol;
	return root->data;
}

agac * silme(agac*root, int deger){
	if(root==NULL)
		return NULL;
	if(root->data==deger){
		if(root->sol==NULL & root->sag==NULL){
			return NULL;
		}
		if(root->sag!=NULL){
			root->data=min(root->sag);
			root->sag=silme(root->sag,min(root->sag));
			return root;
		}
		root->data=max(root->sol);
		root->sol=silme(root->sol,max(root->sol));
		return NULL;		
	}
	if(deger > root->data){
		root->sag=silme(root->sag, deger);
		return root;
	}
	root->sol=silme(root->sol, deger);
	return root;
}



void inorder(agac*root){
	if(root==NULL)
		return;
	inorder(root->sol);
	printf("%d ", root->data);
	inorder(root->sag);
}


int yukseklik(agac* root,int lh, int rh, int toplam)
{	
    if (root == NULL)
        return toplam;
        
	toplam = yukseklik(root->sol,++lh,rh,toplam);
    lh--;
    
	if(root->sag==NULL&&root->sol==NULL){
		temptoplam=lh+rh;
	}
	
	if(temptoplam>toplam)
		toplam=temptoplam;
        
	toplam = yukseklik(root->sag, lh,++rh,toplam);

	return toplam;
}
   


int fullbin(agac*root, int x){
	int solh, sagh;
	if(root==NULL){
		return x;
	}
	if ((root->sol!=NULL && root->sag!=NULL)||root->sol==NULL&&root->sag==NULL){
		solh=yukseklik(root->sol,lh,rh,toplam);
		sagh=yukseklik(root->sag,lh,rh,toplam);
		if(solh==sagh){
			x=1;
			x = fullbin(root->sol,x);
			x = fullbin(root->sag,x);
		}
		else
			x=0;
	}
	else{
		x=0;
	}
	return x;
}

int completebin(agac*root, int x){
	if(root==NULL){
		return x;
	}
	if ((root->sol!=NULL && root->sag!=NULL)||root->sol==NULL&&root->sag==NULL){
		x=1;
		x = fullbin(root->sol,x);
		if(x == 0)
			return x;
		x = fullbin(root->sag,x);
	}
	else{
		x=0;
	}
	return x;
}

int sayac(agac*root){
	if(root==NULL)
		return t;
	t++;
	t=sayac(root->sol);
	t=sayac(root->sag);
	return t;
}

int toplamm(agac*root){
	if(root==NULL)
		return t;
	t+=root->data;
	t=toplamm(root->sol);
	t=toplamm(root->sag);
}



int main(){
	int secim;
	int deger;
	int h;
	int x;
	while(true){
		printf("1.Ekleme\n2.Silme\n3.Inorder Siralama\n4.Agacin Yuksekligini Bulma\n5.Full Binary Kontrol\n6.Complete Binary Kontrol\n");
		printf("Yapacaginiz islemi giriniz: ");
		scanf("%d", &secim);
		switch(secim){
			case 1:
				printf("Eklemek istediginiz degeri girin: ");
				scanf("%d", &deger);
				root=ekle(root, deger);
				break;
			case 2:
				printf("Silmek istediginiz degeri girin: ");
				scanf("%d", &deger);
				root=silme(root,deger);
				break;
			case 3:
				inorder(root);
				printf("\n");
				break;
			case 4:
				h=yukseklik(root,lh,rh,toplam);
				printf("Agacin Yuksekligi: %d\n", h);
				break;
			case 5:
				x=fullbin(root, x);
				if(x==1)
					printf("Agac Full Binary\n");
				else
					printf("Agac Full Binary Degil\n");	
				break;
			case 6:
				x=completebin(root,x);
				if(x==1)
					printf("Agac Complete Binary\n");
				else
					printf("Agac Complete Binary Degil\n");	
				break;
			case 7:
				t=sayac(root);
				printf("Toplam eleman:%d\n", t);
				t=0;
				break;
			case 8:
				t=toplamm(root);
				printf("Toplam eleman:%d\n", t);
				t=0;
				break;
			default:
				printf("Hatali giris yaptiniz. Tekrar deneyin");
				break;
				
				
			
	}
	}
	
}

