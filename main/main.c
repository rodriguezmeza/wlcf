// ============================================================================
//        1          2          3          4        ^ 5          6          7

#define GLOBAL
#define global

#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "procedures.h"
#include "functions.h"
#include "background.h"
#include "zetam.h"

#include "cmdline_defs.h"

int main(int argc, string argv[])
{
    struct cmdline_data cmd;                        // share command parameters
    struct global_data gd;                          // share global parameters
	clock_t start_t, end_t;
	start_t = clock();

	InitParam(argv, defv);
    StartRun(&cmd, &gd, argv[0],                    // get parameters and
             HEAD1, HEAD2, HEAD3);                  //  init global structure
                                                    //  and do other useful
                                                    //  process, like param
                                                    //  check, ...
    Initial(&cmd, &gd);
    MainLoop(&cmd, &gd);
    free_variables(&cmd, &gd);
	end_t = clock();
	printf("Total time: %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC  );

    return SUCCESS;
}


int MainLoop(struct cmdline_data* cmd, struct  global_data* gd)
{
    string routineName = "MainLoop";
	gv.time=clock();
	background(cmd, gd, cmd->zbin);
	if(cmd->chatty>1){
		printf("time evaluating background: %lf s\n", (double)(clock() - gv.time) / CLOCKS_PER_SEC );
		printf("iv.chiMaxInt = %f Mpc/h\n", iv.chiMaxInt);
		printf("gv.chiBin    = %f Mpc/h\n", gv.chiBin);
	 }

	//~ printf("\n chiOfzT= \n {");    
	//~ for	(int i=0;i<gv.Nz;i++) printf("{%f, %f}, ", gv.zT[i], gv.chiOfzT[i]);
	//~ printf("} \n");    
        
    debug_tracking_s("001", routineName);

    gv.time=clock();
	gv.z=cmd->zbin;
	gv.Dp = Dplusf(cmd, gd, gv.z)/gd->Dpz0;

    debug_tracking_r("002", gd->Dpz0);

    gv.r_sigma = calcrsigma(cmd, gd, gv.Dp, 0.001,8.,100);
	gv.n_eff= n_eff_func(cmd, gd, gv.r_sigma,gv.Dp,0.001,8.,100);
	BmKspace(cmd, gd, cmd->mMax, 0.001, 1.0, 100, cmd->GLpoints, gv.z,gv.Dp,gv.r_sigma,gv.n_eff);
    printf("time= %lf \n", (double)(clock() - gv.time) / CLOCKS_PER_SEC );
     
	allocate_iv(cmd, gd);
	gv.time=clock();
	Bmell(cmd, gd);
	if(cmd->chatty>1) printf("Integration time= %lf \n", (double)(clock() - gv.time) / CLOCKS_PER_SEC );
	
	allocate_zv();
	get_zetam(cmd, gd);

	write(cmd, gd);
	
	//Tests();
	  	
    return SUCCESS;
}


void Tests(void)
{	
	//read and write
	//~ FILE *fp;
	//~ int size = iv.Nell*iv.Nell;
	//~ int n_data, ndatamax;
    //~ double Bmell0vector[size];
    //~ double mat[iv.Nell][iv.Nell];
    //~ int i;
    
	//~ fp = fopen("outputs/1_BmellsVector_0.txt", "r");    
     
    //~ ndatamax = size;
    
    //~ n_data=0;
    //~ if (NULL == fp) {
        //~ printf("\n\nfile can't be opened \n\n");
    //~ }
    //~ if(fp!=NULL){   
		//~ while(fscanf(fp, "%lf", &Bmell0vector[n_data])!=EOF){
			//~ n_data++;
			//~ if(n_data>ndatamax) printf("n_data_max should be larger than the number of data lines \n");
		//~ }	  	
	//~ fclose(fp);		
	//~ }
    
 	//~ for(int i=0;i<size; i++){
	//~ printf("%e,  ",Bmell0vector[i]);	
	//~ }   
    
    //~ printf(" \n");
	//~ for(int i=0; i<iv.Nell ; i++){
	//~ for(int j=0; j<iv.Nell ; j++){
			//~ mat[i][j] = Bmell0vector[i*iv.Nell+j];	
	//~ }
	//~ }    
    
    //~ printf(" \n");
	//~ for(int i=0; i<iv.Nell ; i++){
	//~ for(int j=0; j<iv.Nell ; j++){	
			//~ printf("%15e ", mat[i][j]);
			//~ if(j==iv.Nell-1) printf(" \n");
	//~ }
	//~ } 



}

//B socket:
#ifdef ADDONS
#include "wlcf_include_05.h"
#endif
//E







