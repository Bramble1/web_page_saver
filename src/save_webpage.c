#include<stdio.h>
#include<curl/curl.h>

/*@curl - the data structure containing relevant information for performing a https get request
 * @webpage - the name of the webpage we will be attempting to download*/
void setup_get_request(CURL **curl,char *webpage)
{
	curl_easy_setopt(*curl,CURLOPT_URL,webpage);
}

/*@curl - the data structure containing relevant https get information
 * @res - the return value to check if the get request was succesful or not*/
void perform_get_request(CURL **curl)
{
	CURLcode res;
	res =curl_easy_perform(*curl);
	if(res!=CURLE_OK)
	{
		fprintf(stderr,"curl_easy_perform() failed:%s\n",curl_easy_strerror(res));
	}
}

int main(int argc, char *argv[])
{

	CURL *curl;

	/*setup procedure for curl library*/
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if(curl)
	{	
		setup_get_request(&curl,argv[1]);
		
		perform_get_request(&curl/*,res*/);	

		/*perform cleanup*/
		curl_easy_cleanup(curl);
	}
	/*perform global cleanup*/
	curl_global_cleanup();

	return 0;
}
