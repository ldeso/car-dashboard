# Integration test #2
## Object: inna_scene.h / inna_scene.cpp intergrated in **Serveur**
#### Date: 03/12/2019 
#### Done by : Lobanova Inna
_**Prerequisite**:_
1. Run the ptoject Server 
2. Run the project Client
3. Enter the following commands in the console window of Client

Test Execution Steps:

| S. No | Command | Expected Output Client | Actual Output Client | Expected output Server | Actual output Server | Test Result| Test Comments |
 | :--: | :--  | :--- | :--  | :--  | :--  | :--:  | :--  |
 | 1|CANN SPEED 10 | OK | OK | 1. Speedometer arrow pointing at 10 km/h <br/> 2. The display shows 10 km/h                                                                                                                                                                                            | 1. Speedometer arrow pointing at 10 km/h <br/> 2. The display shows 10 km/h| Passed||
 | 2|CANN SPEED 100 | OK | OK| 1. Speedometer arrow pointing at 100 km/h <br/> 2. The display shows 100 km/h| 1. Speedometer arrow pointing at 100 km/h <br/> 2. The display shows 100 km/h| Passed | |
 | 3| CANN SPEED 350 | vitesse incorrect, vitesse comprise entre 0 et 300 | vitesse incorrect, vitesse comprise entre 0 et 300 | 1. Speedometer arrow pointing at 300 km/h <br/> 2. The display shows 300 km/h| 1. Speedometer arrow pointing at the last valid value 2. The display shows last valid value | Not Passed |  needs to be implementer in Server |
 |4| CANN SPEED -10 | vitesse incorrect, vitesse comprise entre 0 et 300| vitesse incorrect, vitesse comprise entre 0 et 300 | 1. Speedometer arrow pointing at 0 km/h <br/> 2. The display shows  0 km/h| 1. Speedometer arrow pointing at the last valid value 2. The display shows last valid value| Not Passed|  needs to be implementer in Server|
 | 5| cann BATTERY_LIGHT 1 | OK | OK| Display the Battery icon | the Battery icon is displayed | Passed                        |
 | 6| cann BATTERY_LIGHT 0 | OK | OK| The Battery icon is not displayed | the Battery icon is not displayed | Passed |
 | 7| cann BATTERY_LIGHT with value different of 1 and 0 | valeur incorrecte, doit être égale à 0 ou 1 | valeur incorrecte, doit être égale à 0 ou 1| The Battery icon is not displayed    | the Battery icon is not displayed | Passed |

 