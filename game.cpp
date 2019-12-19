#include<bits/stdc++.h>
#include<unistd.h>
int static highestscore = 0, hscorevarfile = 0;
using namespace std;


int loadprobab[4] = {4, 3, 2, 1};

int init=5; //Initial speed value

int findload(int val)
{
	int i=0;
	int summ=0;
	for(i=0;i<4;i++)
	{
		summ+=loadprobab[i];
		if(val<=summ )
		{
			return i;
		}
	}
}
int createload()
{
	float val = (rand()% 10 + 1);
	return findload(val)+1;
}

bool createjump()
{
	return 1;
}

int jumpLoadProbab()
{

	int x1 = rand() & 1;
	int x2 = rand() & 1;
	
	int x3 = x1 | x2;
	
	return x3; // return 1 for jumping up or 0 for going down with load
}
int main()
{
	cout<<"Initial ";
//getting file current working directory and file address for data I/O
fstream file;
char cwd[100];
char fileaddress[20] = "/gamedata/data.txt";
getcwd(cwd, sizeof(cwd));
strcat(cwd, fileaddress);
//cout<<cwd;

file.open(cwd);

if(!file)
	cout<<"No such file";
file>>hscorevarfile;
//cout<<hscorevarfile<<endl;
	int index;
	int currentstate = init;
	
	cout<<"Load Level: "<<index<<endl;	
	
	srand(time(0));
	int flag = 0;
	//for(int i=0;i<200;i++)
	while(currentstate>0)
	{
		/*if(currentstate == 0)
			return 0;*/
		
		int outcome = jumpLoadProbab();
		int red;
		
		((currentstate>33) ? flag = 1 : red = 0 );
		
		if(flag == 1) //threasold at reversing good and bad stuffs to make player lose
		{
			//cout<<"\nFlag Activated\n";
			if(outcome == 1)
				outcome = 0;
			else if(outcome == 0)
				outcome = 1;	
		}
		((currentstate>highestscore) ? highestscore = currentstate : red = 0);
		
		if(outcome)
		{
			//if value is 1 create jump.
			currentstate += createjump();
			cout<<"\nTRUE Jump \t Increased BY 1 levels: \t current level: "<<currentstate;
		}
		else
		{
			//else if value is 0 create load/downfall.
			index = createload();
			currentstate -= index;
			cout<<"\n \t LoadLevel: "<<index;
			if(currentstate<0)
				currentstate=0;
				
			cout<<"\nFALSE Drop \t Reduced BY "<<index<<" levels: \t\t current level: "<<currentstate;	
		}
		
	}
	cout<<"\n\nHighest Score in this game: "<<highestscore;
	if(highestscore>hscorevarfile)
	{
		ofstream file2;
		file2.open(cwd, ios::trunc);
		file2<<highestscore;
	}
	cout<<"\n\nHighest Score ever: "<<hscorevarfile;
}

