void BK(int k) //k-pozitia din vector care se completeaza
{int i;
for (i=1; i<=nr_elemente_Sk; i++) //parcurge elementele multimii Sk
 { v[k]=i; //selecteaza un element din multime
 if (validare(k)==1) 
 { if (solutie(k)==1) 
 afisare(k); 
 else
 BK(k+1); 
 }
 } 
}
