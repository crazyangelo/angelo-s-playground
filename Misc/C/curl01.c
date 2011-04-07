#include <stdio.h>
#include <curl/curl.h>
 
int main(void) {
	CURL *curl;
	CURLcode res;
	FILE *fp;

	if((fp = fopen("ibm.txt", "w+")) == NULL)
		printf("file open error\n");

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "ichart.finance.yahoo.com/table.csv?s=IBM&d=8&e=12&f=2010&g=d&a=0&b=2&c=2000&ignore=.csv");
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);

	/* always cleanup */ 
	curl_easy_cleanup(curl);

	fclose(fp);
	}
	return 0;
}
