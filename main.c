/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: user
 *
 * Created on 15 апреля 2018 г., 12:10
 */

typedef signed char      int8;
typedef signed short     int16;
typedef signed int       int32;
typedef signed long      int64;
typedef unsigned char    uint8;
typedef unsigned short   uint16;
typedef unsigned int     uint32;
typedef unsigned long    uint64;

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <zlib.h>
#include "rtypes.h"
#include "option.h"
#include "rprm.h"
#include "fitdata.h"
#include "version.h"

#include "fitread.h"
#include "oldfitread.h"

#include "errstr.h"
#include "hlpstr.h"

struct RadarParm *prm;
struct FitData *fit;
struct OptionData opt;

int main(int argc, char** argv) {

/* File format transistion
   * ------------------------
   * 
   * When we switch to the new file format remove any reference
   * to "new". Change the command line option "new" to "old" and
   * remove "old=!new".
   */


  int old=0;
  int new=0;


  int arg;
//  unsigned char help=0;
//  unsigned char option=0;

  int i;
  struct OldFitFp *fitfp=NULL;
  FILE *fp=NULL;
  int c;

  prm=RadarParmMake();
  fit=FitMake();
/*
  OptionAdd(&opt,"-help",'x',&help);
  OptionAdd(&opt,"-option",'x',&option);


  OptionAdd(&opt,"new",'x',&new); 

  arg=OptionProcess(1,argc,argv,&opt,NULL);

  old=!new;


  if (help==1) {
    OptionPrintInfo(stdout,hlpstr);
    exit(0);
  }

  if (option==1) {
    OptionDump(stdout,&opt);
    exit(0);
  }


  if ((old) && (arg==argc)) {
    OptionPrintInfo(stdout,errstr);
    exit(-1);
  }
*/
  fp = NULL;
  fp = fopen("20130101.0001.00.hok.fitacf", "r");
  if (fp==NULL) {
      fprintf(stderr,"Could not open file.\n");
      exit(-1);
  }
    
  while (FitFread(fp,prm,fit) !=-1) {
        fprintf(stdout,"%d %d\n",fit->revision.major,fit->revision.minor);
        fprintf(stdout,
                "%d-%d-%d %d:%d:%d beam=%d  bmazm=%f channel=%d cpid=%d scan=%d\n",
                prm->time.yr,prm->time.mo,prm->time.dy,
                prm->time.hr,prm->time.mt,prm->time.sc,
                prm->bmnum,prm->bmazm,prm->channel,prm->cp,prm->scan);
        fprintf(stdout,"origin.code=%c\norigin.time=%s\norigin.command=%s\n",
                prm->origin.code,prm->origin.time,prm->origin.command);
        fprintf(stdout,"combf=%s\n",prm->combf);
        fprintf(stdout,"v:\n");
        
        for (i=0;i<prm->nrang;i++) {
            fprintf(stdout,"%.4g",fit->rng[i].v);
            if ((i % 8)==0) fprintf(stdout,"\n");
            else fprintf(stdout,"\t");
        }
        
        fprintf(stdout,"\n");
        fprintf(stdout,"v_e:\n");
        
        for (i=0;i<prm->nrang;i++) {
           fprintf(stdout,"%.4g",fit->rng[i].v_err);
           if ((i % 8)==0) fprintf(stdout,"\n");
           else fprintf(stdout,"\t");
        }
        
        fprintf(stdout,"\n");
        fprintf(stdout,"p_l:\n");
        
        for (i=0;i<prm->nrang;i++) {
            fprintf(stdout,"%.4g",fit->rng[i].p_l);
            if ((i % 8)==0) fprintf(stdout,"\n");
            else fprintf(stdout,"\t");
        }
        
        fprintf(stdout,"\n");
        fprintf(stdout,"w_l:\n");
        
        for (i=0;i<prm->nrang;i++) {
            fprintf(stdout,"%.4g",fit->rng[i].w_l);
            if ((i % 8)==0) fprintf(stdout,"\n");
            else fprintf(stdout,"\t");
        }
        
        fprintf(stdout,"\n");
  }
  if (fp !=stdin) fclose(fp);
  return 0;
}