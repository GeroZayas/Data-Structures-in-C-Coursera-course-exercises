#include "stuff.h"
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  CURL *curl;
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (curl) {
    puts("INSERT URL: ");
    char url[200];
    scanf("%s", url);
    puts(url);
    printf("SIZE OF URL == %zu\n == CHARACTERS", sizeof(url));
    curl_easy_setopt(curl, CURLOPT_URL, url);
    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
      fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
    }
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}

