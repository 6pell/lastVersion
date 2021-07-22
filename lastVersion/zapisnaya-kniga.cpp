#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "model.h"
#include "people.h"
#include <cstdlib>
#include "Presenter.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    Presenter myPresenter;
    myPresenter.start();
}
