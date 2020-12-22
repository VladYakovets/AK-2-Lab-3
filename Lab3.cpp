#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char * const argv[]){
	int h_count = 0;
	int i_count = 0;
	int f_count = 0;
	int l_count = 0;


    const char* short_options = "hif::l::";

    const struct option long_options[] = {
        {"help",0, NULL, 'h'},
        {"info",0, NULL, 'i'},
        {"float",2, NULL, 'f'},
        {"list",2, NULL, 'l'},
        {NULL,0,NULL,0}
    };
    int count;
    int option_index = -1;
    while ((count=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){
    	switch (count) {
    		case 'h': {
    			if (h_count < 1){
    				if (option_index<0)
						printf("Arg: short help\n");
					else
						printf("Arg: long help\n");
    			};
                h_count ++;
    			break;
    		};
    		case 'i': {
				if (i_count < 1)
					printf("Arg: info\n");
				i_count ++;
				break;
			};
			case 'f':{
				if (i_count < 1)
					if (optarg != NULL)
						printf("Arg: float, Value of Float: %s\n", optarg);
					else
						printf("Arg: float\n");
				f_count ++;
				break;
			};
			case 'l':{
				if (l_count < 1)
					if (option_index > 0 && optarg != NULL)
						printf("Arg: list, elements of List: %s\n", optarg);
					else
						printf("Arg: list\n");
				l_count ++;
				break;
			};
			default: {
				printf("found unknown option\n");
				break;
			};
		};
		option_index = -1;

    };

};
