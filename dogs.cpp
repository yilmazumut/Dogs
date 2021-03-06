
//minimum remaining value

#include <iostream>
#include <istream>
#include <string>
#include <algorithm>

using namespace std;

class Node {
    protected:
        string _has;
        int position_x,position_y;
        int _minimumRemainingValue;

    public:
        Node(){
            _minimumRemainingValue = 0;
            _has = "O";
            position_x = -1;
            position_y = -1;
        }
        // getter and setter for _has
        string getHas(void){
            return _has;
        }

        void setHas(string has){
            _has = has;
            return;
        }

        //getters and setters for position

        int getPositionX(void) {
            return position_x;
        }

        int getPositionY(void){
            return position_y;
        }

        void setPositionX(int x){
            position_x = x;
        }

        void setPositionY(int y){
            position_y = y;
        }

        // getter and setter for mrv
        int getMrv(void){
            return _minimumRemainingValue;
        }

        void setMrv(int mrv){
            _minimumRemainingValue = mrv;
            return;
        }

        //Add to minimum remaining value
        void addMrv(int add){
            _minimumRemainingValue += add;
            return;
        }
};

class Dog : public Node{
public:
    Dog() {
      _has = "D";
      _minimumRemainingValue = 0;
      position_x = -1;
      position_y = -1;
    }
};

class Tree : public Node{
public:
    Tree() {
        _minimumRemainingValue = 100;
        _has = "T";
        position_x = -1;
        position_y = -1;
    }
};

int main(){
//initialize variables and take inputs
int dimension,numberOfTree;
int i,j;
cout << "Please enter dimension(nxn) and number of trees,respectively: ";
cin >> dimension >> numberOfTree;
int restriction[dimension*2]={0};
//int nodeNumber = dimension*dimension;
Node* table[dimension][dimension] = {NULL};
string tempTable;
string columnRest,rowRest,columnRestriction,rowRestriction;
int treePositions[numberOfTree*2]={0}; // to find trees easily.
int treeCounter=0;
cout << "Enter column restriction without space: ";
cin >> columnRest;
cout << "Enter row restriction without space: ";
cin >> rowRest;

//arrange column restrictions
for(i = 0;i < dimension;i++){
    columnRestriction[i] = columnRest[i];
}
//arrange row restrictions
for(j = 0;i < dimension;i++,j++){
    rowRestriction[i] = rowRest[j];
}


//initialize table
cout << "table is initializing...\n";
for(i = 0;i < dimension;i++){
    cin >> tempTable;
    for(j=0;j<dimension;j++){
        if(tempTable[j] == 'O'){
            table[i][j] = new Node();
            table[i][j] -> setPositionX(i);
            table[i][j] -> setPositionY(j);
        }
        else if(tempTable[j] == 'T'){
            table[i][j] = new Tree();
            table[i][j] -> setPositionX(i);
            table[i][j] -> setPositionY(j);
            treePositions[treeCounter] = i;
            treePositions[treeCounter+1] = j;
            treeCounter += 2;
        }
        else if(tempTable[j] == 'D'){
            table[i][j] = new Dog();
            table[i][j] -> setPositionX(i);
            table[i][j] -> setPositionY(j);
        }

    }

}
cout << "table is initialized...\n";

//assign mrvs
cout << "mrvs assigning...\n";
for(i=0;i<dimension;i++){
        if(i == 0){
            for(j=0;j<dimension;j++){
                if(table[i][j]->getHas() == "O"){
                    if(j==0){
                        //right
                        if(table[i][j+1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //down
                        if(table[i+1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                    else if(j==dimension-1){
                        //left
                        if(table[i][j-1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //down
                        if(table[i+1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                    else {
                        //right
                        if(table[i][j+1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //left
                        if(table[i][j-1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //down
                        if(table[i+1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                        table[i][j]->addMrv(columnRestriction[j]);
                        table[i][j]->addMrv(rowRestriction[i]);

                    }

                }
            }

        else if(i == dimension-1){
            for(j=0;j<dimension;j++){
                if(table[i][j]->getHas() == "O"){
                    if(j==0){
                        //right
                        if(table[i][j+1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //up
                        if(table[i-1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                    else if(j==dimension-1){
                        //left
                        if(table[i][j-1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //up
                        if(table[i-1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                    else {
                        //right
                        if(table[i][j+1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //left
                        if(table[i][j-1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //up
                        if(table[i-1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }

                    table[i][j]->addMrv(columnRestriction[j]);
                    table[i][j]->addMrv(rowRestriction[i]);
                }
            }
        }
        else{
            for(j=0;j<dimension;j++){
                if(table[i][j]->getHas() == "O"){
                    if(j==0){
                        //right
                        if(table[i][j+1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //up
                        if(table[i-1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //down
                        if(table[i+1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                    else if(j==dimension-1){
                        //left
                        if(table[i][j-1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //up
                        if(table[i-1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //down
                        if(table[i+1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                    else {
                        //right
                        if(table[i][j+1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //left
                        if(table[i][j-1]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //up
                        if(table[i-1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                        //down
                        if(table[i+1][j]->getHas() == "T"){
                            table[i][j]->addMrv(5);
                        }
                    }
                        table[i][j]->addMrv(columnRestriction[j]);
                        table[i][j]->addMrv(rowRestriction[i]);
                    }

                    }

                }

    }
cout << "Mrv of first node is " << table[0][0]->getMrv() << endl;
cout << "mrvs assigned...\n";
//choose minimum _minimumRemainingValue if there is no D in that node and its neighbours
// we use treePositions table to determine trees' locations.
Node minimum;
cout << "placing dogs...\n";
int treeRow,treeColumn,minimumX,minimumY;
for(i=0;i<numberOfTree*2;i+=2){
    treeRow = treePositions[i];
    treeColumn = treePositions[i+1];
    minimum = *table[treeRow][treeColumn]; //position of tree
    minimumX = minimum.getPositionX(); // position of tree
    minimumY = minimum.getPositionY(); //position of tree
    if(treeRow==0){
        if(treeColumn==0){
            //right
            if(table[minimumX][minimumY+1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY+1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //down
            if(table[minimumX+1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX+1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            table[minimumX][minimumY] = new Dog();
        }
        else if(treeColumn == dimension-1){
            //down
            if(table[minimumX+1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX+1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //left
            if(table[minimumX][minimumY-1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY-1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            table[minimumX][minimumY] = new Dog();

        }
        else{
            //left
            if(table[minimumX][minimumY-1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY-1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //down
            if(table[minimumX+1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX+1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }

            //right
            if(table[minimumX][minimumY+1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY+1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            table[minimumX][minimumY] = new Dog();
        }
    }
    else if(treeRow == dimension-1){
        if(treeColumn==0){
            //up
            if(table[minimumX-1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX-1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //right
            if(table[minimumX][minimumY+1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY+1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }

            table[minimumX][minimumY] = new Dog();
        }
        else if(treeColumn == dimension-1){
            //up
            if(table[minimumX-1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX-1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //left
            if(table[minimumX][minimumY-1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY-1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            table[minimumX][minimumY] = new Dog();

        }
        else{
            //left
            if(table[minimumX][minimumY-1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY-1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }

            //up
            if(table[minimumX-1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX-1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //right
            if(table[minimumX][minimumY+1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY+1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            table[minimumX][minimumY] = new Dog();
        }
    }
    else{
        if(treeColumn == 0){
            //right
            if(table[minimumX][minimumY+1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY+1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //up
            if(table[minimumX-1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX-1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //down
            if(table[minimumX+1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX+1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            table[minimumX][minimumY] = new Dog();
        }
        else if(treeColumn == dimension-1){
            //up
            if(table[minimumX-1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX-1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //down
            if(table[minimumX+1][minimumY]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX+1][minimumY];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            //left
            if(table[minimumX][minimumY-1]->getMrv() <= minimum.getMrv()){
                minimum = *table[minimumX][minimumY-1];
                minimumX = minimum.getPositionX();
                minimumY = minimum.getPositionY();
            }
            table[minimumX][minimumY] = new Dog();
        }
    }
}

cout << "dogs placed...\n";


return 0;
}
