// Keyboard Matrix Tutorial Example
// baldengineer.com
// CC BY-SA 4.0
  
// JP1 is an input
byte rows[] = {2,3};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
// JP2 and JP3 are outputs
byte cols[] = {22,23};
const int colCount = sizeof(cols)/sizeof(cols[0]);
 
byte keys[colCount][rowCount];
 
void setup() {
    Serial.begin(9600);
 
    for(int x=0; x<rowCount; x++) {
        Serial.print(rows[x]); Serial.println(" as input");
        pinMode(rows[x], INPUT);
    }
 
    for (int x=0; x<colCount; x++) {
        Serial.print(cols[x]); Serial.println(" as input-pullup");
        pinMode(cols[x], INPUT_PULLUP);
    }
}
 
void readMatrix() {
    // iterate the columns
    for (int colIndex=0; colIndex < colCount; colIndex++) {
        // col: set to output to low
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);
 
        // row: interate through the rows
        for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            keys[colIndex][rowIndex] = digitalRead(rowCol);
            pinMode(rowCol, INPUT);
        }
        // disable the column
        pinMode(curCol, INPUT);
    }
}
 
void printMatrix() {
    for (int rowIndex=0; rowIndex < rowCount; rowIndex++) { //samples all rows
        for (int colIndex=0; colIndex < colCount; colIndex++) {  //samples all columns
            if (keys[colIndex][rowIndex] == 0) {
              String StrVal = String(colIndex) + "," + String(rowIndex); //concatonate coordinate of button press
              Serial.println(StrVal); //adds new line so if multiple buttons are pressed, it still works.
            }
        }   
    }
}
 
void loop() {
    readMatrix();
    printMatrix();
    delay(50); //not too quickly; can be changed
}
