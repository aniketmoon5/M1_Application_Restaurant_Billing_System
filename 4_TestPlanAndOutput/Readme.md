## Test plan

## High Level Test Plan

| Test_Id  |     Desciption       |  Expected_Input | Expected_output  | Actual_Output | Type_of_Test |
| -------- |   --------------     |  -------------- | ---------------  | ------------- | -------------|
| HLR_1    |  Generate Invoice    | BillHeader()    |       PASS       |      Pass     | Requrirement |
                                  |   BillBody()    |                                
                                  |  BillFooter()   |                               
                                    
## Low Level Test Plan

| Test_Id  |            Desciption                     |  Expected_Input | Expected_output      | Actual_Output | Type_of_Test |
| -------- |   ------------------------------------    |  -------------- | ---------------      | ------------- | -------------|
| LLR_1    |          Search Invoices                  |  Read file      | Previous invoices    | Pass          | Requrirement |
| LLR_2    |               Exit                        |  Option 4       | Exits                | Pass          | Requrirement |
| LLR_3    |            Save Inoice                    |  'y'            | Saves Invoice        | Pass          | Requrirement |
