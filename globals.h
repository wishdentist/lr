
   
.................
.................
.................

   registerHeaders();

   web_custom_request("!STANDARD_39",
       "URL=http://{HOST}:{PORT}/prweb/PRServlet/O-vwnGkOMJTiba4-9fqRB__Lew2XerZU*/!STANDARD?pyActivity=ReloadSection&pzTransactionId=&pzFromFrame=&pzPrimaryPageName=pyDisplayHarness&ReadOnly=0&StreamName=MyWorklistTab&StreamClass=Rule-HTML-Section&BaseReference=&bClientValidation=true&FieldError=&FormError=&pyCustomError=&pzKeepPageMessages=true&pyCallStreamMethod=simpleLayout_3&pyLayoutMethodName=simpleLayout_3&UITemplatingStatus=Y&inStandardsMode=true&AJAXTrackID=1&pzHarnessID={HID_common_23}&HeaderButtonSectionName=",
       "Method=POST",
       "TargetFrame=",
       "Resource=0",
       "RecContentType=text/html",
       "Referer=http://{HOST}:{PORT}/prweb/PRServlet/O-vwnGkOMJTiba4-9fqRB__Lew2XerZU*/!STANDARD?pzPostData=340695838",
       "Snapshot=t1038.inf",
       "Mode=HTML",
       "Body=$OCompositeGadgetPortal=&$OControlMenu=&$ODesktopWrapperInclude=&$ODeterminePortalTop=&$ODynamicContainer=&$ODynamicLayout=&$ODynamicLayoutCell=&$OEvalDOMScripts_Include=&$OGapIdentifier=&$OHarnessStaticJSEnd=&$OHarnessStaticJSStart=&$OHarnessStaticScriptsClientValidation=&$OLaunchFlow=&$OMenuBar=&$OMenuBarOld=&$OMobileAppNotify=&$OSessionUser=&$OWorkAreaTabsCntnr=&$OWorkformStyles=&$OmenubarInclude=&$OpxButton=&$OpxIcon=&$OpxLayoutContainer=&$OpxLink=&$OpxMenu=&$OpxNonTemplate=&$OpxSection=&$OpxVisible=&$OpyWorkFormStandardEnd=&$OpyWorkFormStandardStart=&$OpzHarnessInlineScriptsEnd=&$OpzHarnessInlineScriptsStart=&$OpzRuntimeToolsBar=&$Opzpega_ui_harnesscontext=&$Osearch=&$OsearchPanel=&$OsearchPanel_disableEnterKey=&$OxmlDocumentInclude=",
       LAST);

   web_revert_auto_header("Origin");

   web_revert_auto_header("X-Requested-With");

   lr_end_transaction("NBP_BK_05_01_Login_ManagerMan", LR_AUTO);

   saveHeaders();    clear_everything_you_need();
   
.................
.................
.................
















A01_ManagerMan()
{
set_headers(1);


web_custom_request("!STANDARD_4",
       "URL=http://{HOST}:{PORT}/prweb/PRServlet/O-vwnGkOMJTiba4-9fqRB__Lew2XerZU*/!STANDARD?pyActivity=pzGetMenu&pzTransactionId=&pzFromFrame=&pzPrimaryPageName=pyDisplayHarness&navName=StartProcessMenu&pzKeepPageMessages=true&removePage=true&UITemplatingStatus=Y&showmenucall=true&navPageName=pyNavigation1582710036007&pzHarnessID={HID_common}&inStandardsMode=true&AJAXTrackID=1&HeaderButtonSectionName=",
       "Method=POST",

.................
.................
.................


    registerHeaders();

   web_submit_data("!TABTHREAD0_335",
       "Action=http://{HOST}:{PORT}/prweb/PRServlet/O-vwnGkOMJTiba4-9fqRB__Lew2XerZU*/!TABTHREAD0?pyActivity=FinishAssignment&pzFromFrame=pyWorkPage&pzPrimaryPageName=pyWorkPage&pzTransactionId={pzTransactionId_common_5}&pzHarnessID={HID_common_6}",
       "Method=POST",
       "TargetFrame=",

    saveHeadersToPosition(1);

   clear_everything_you_need();
   
return 0;
}


























#ifndef _GLOBALS_H
#define _GLOBALS_H

#define numberOfUsers 10

#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"
#include "stdio.h"
#include "string.h"

//---------------------------------------------------------------------------
// Include Files
//---------------------------------------------------------------------------
// globals.h v1.0
// changes: dynamic length of jsessionId and PegaRules cookies supported now
//---------------------------------------------------------------------------

//arrays of JSESSIONID's and Pega-Rules's headers
char * jSessionIds[numberOfUsers];
char * pegaRulesss[numberOfUsers];

//temp variable for processing strings
char * pointerToString;

//temp variable for debug messages
char kek[100];
   
//--------------------------------------------------------------------
// Global Variables



void clear_everything_you_need(){
       web_cache_cleanup();         // Cleans the content of the cache simulator.
       web_cleanup_auto_headers(); //  Removes all previous customized headers from HTTP requests.
       web_cleanup_cookies();        //    Removes all cookies currently stored by the Vuser.
   return;
}



// saving headers in the following request
// can save tem only from outgoing request headers
void registerHeaders(){
   web_save_header(REQUEST, lr_eval_string("request_header") );
   return;
}



// pushing new JSESSIONID and Pega-Rules ids to array from loadrunner parameter, which is saved in "registerHeaders()"
int saveHeaders(){
   char * pegaRules;
   char * jSessionId;
   int length = 0;
   
   if(strstr(lr_eval_string("{request_header}"), "Pega-RULES=") != NULL) {
       
       if ((pegaRules = (char *)malloc(100 * sizeof(char))) == NULL) {
           lr_output_message ("Insufficient memory available");
           return -1;
       }
       
       if ((jSessionId = (char *)malloc(100 * sizeof(char))) == NULL) {
           lr_output_message ("Insufficient memory available");
           return -1;
       }
       
       // searching for substring "Pega-RULES=" and savign next 33 symbols to array
       pointerToString = (char * ) strstr(lr_eval_string("{request_header}"), "Pega-RULES=");
       pointerToString += 11;
       strncpy( pegaRules, pointerToString, 100 );
               //----------------------------
               // cut the garbage ending of jsessionId draftstring  (and also finishing string)
           while(pegaRules[length]!='\0') {        
               if ( (pegaRules[length]==';') || (pegaRules[length]==' ') || (pegaRules[length]=='\r') || (pegaRules[length]=='\n') )                    pegaRules[length]='\0';
               ++length;
           }
            //lr_error_message(jSessionId);
               //----------------------------
       pegaRulesss[        arrLength(pegaRulesss) ] = pegaRules;
       
       length = 0;

       if(strstr(lr_eval_string("{request_header}"), "JSESSIONID=") != NULL) {
           pointerToString = (char * ) strstr(lr_eval_string("{request_header}"), "JSESSIONID=");
           pointerToString += 11;
           strncpy(jSessionId, pointerToString, 100 );
                           
           // cut the garbage ending of jsessionId draftstring  (and also finishing string)
           while(jSessionId[length]!='\0') {        
               if ( (jSessionId[length]==';') || (jSessionId[length]==' ') || (jSessionId[length]=='\r') || (jSessionId[length]=='\n') )                    jSessionId[length]='\0';
               ++length;
           }
            //lr_error_message(jSessionId);

           jSessionIds[        arrLength(jSessionIds) ] = jSessionId;
       }
   }
   
   return 0;
}




// replacing fresh JSESSIONID and Pega-Rules ids to array from loadrunner parameter, which is saved in "registerHeaders()"
int saveHeadersToPosition(int position){
   char * pegaRules;
   char * jSessionId;
   int length = 0;
   
   if(strstr(lr_eval_string("{request_header}"), "Pega-RULES=") != NULL) {
       
       if ((pegaRules = (char *)malloc(100 * sizeof(char))) == NULL) {
           lr_output_message ("Insufficient memory available");
           return -1;
       }
       
       if ((jSessionId = (char *)malloc(100 * sizeof(char))) == NULL) {
           lr_output_message ("Insufficient memory available");
           return -1;
       }
       
       // searching for substring "Pega-RULES=" and savign next 33 symbols to array
       pointerToString = (char * ) strstr(lr_eval_string("{request_header}"), "Pega-RULES=");
       pointerToString += 11;
       strncpy( pegaRules, pointerToString, 100 );
               //----------------------------
               // cut the garbage ending of jsessionId draftstring  (and also finishing string)
           while(pegaRules[length]!='\0') {        
               if ( (pegaRules[length]==';') || (pegaRules[length]==' ') || (pegaRules[length]=='\r') || (pegaRules[length]=='\n') )                    pegaRules[length]='\0';
               ++length;
           }
            //lr_error_message(jSessionId);
               //----------------------------
       pegaRulesss[        arrLength(pegaRulesss) ] = pegaRules;
       
       length = 0;
       

       if(strstr(lr_eval_string("{request_header}"), "JSESSIONID=") != NULL) {
           pointerToString = (char * ) strstr(lr_eval_string("{request_header}"), "JSESSIONID=");
           pointerToString += 11;
           strncpy(jSessionId, pointerToString, 100 );
           
           // cut the garbage ending of jsessionId draftstring  (and also finishing string)
           while(jSessionId[length]!='\0') {        
               if ( (jSessionId[length]==';') || (jSessionId[length]==' ') || (jSessionId[length]=='\r') || (jSessionId[length]=='\n') )                    jSessionId[length]='\0';
               ++length;
           }
            //lr_error_message(jSessionId);  
           
           jSessionIds[ position - 1 ] = jSessionId;
       }
   }
   
   return 0;
}




// apply stored headers(cookies)
void set_headers(int num)
{
   char strTo[100];
   strTo[0] = NULL;
   
   strcat(strTo, "Pega-RULES=");
   strcat(strTo, pegaRulesss[num-1]);
   strcat(strTo, "; DOMAIN={HOST}");
   //lr_error_message(strTo);
   web_add_cookie(strTo);
   
   strTo[0] = NULL;
   
   strcat(strTo, "JSESSIONID=");
   strcat(strTo, jSessionIds[num-1]);
   strcat(strTo, "; DOMAIN={HOST}");
   //lr_error_message(strTo);
   web_add_cookie(strTo);
   
   return;
}



// prints first array values until first Null one
void printArrayValues(char **arr)
{
   int length=0;
   while(arr[length]!='\0') {
       kek[0]='\0';
       sprintf(kek, "%s",arr[length]);
       //lr_error_message(kek);
       ++length;        
   }
   return;
}



// count of first non-null elements in array
int arrLength(char **arr){
   int length = 0;
   while(arr[length]!='\0') ++length;
   //kek[0]='\0';
   //sprintf(kek, "%d",length);
   //lr_error_message(kek);
   return length;
}

#endif // _GLOBALS_H  
