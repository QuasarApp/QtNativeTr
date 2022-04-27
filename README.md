# Qt Native Translations library

This is a simple cmake script that generate and build C++ library with all qm translations file of qt.
This is may need to static qt builds and builds for mobile devices like a Android or ios.


## Build and Incude

* cd yourRepo
* git submodule add https://github.com/QuasarApp/QtNativeTr # add the repository of QtNativeTr into your repo like submodule
* git submodule update --init --recursive
* Include in your CMakeLists.txt file the main CMakeLists.txt file of QtNativeTr library
    ``` cmake
    add_subdirectory(QtNativeTr)
    ```
* link the QtNativeTr library to your target
    ```cmake
    target_link_libraries(yourLib PUBLIC QtNativeTr)
    ```
* rebuild yuor project

## Usage 

Simple include resource to your project looks like this:

``` cpp
#include <"QtNativeTr.h">

int main () {

    // init all included resources
    QtNativeTr::init();
    
    return 0;
}

```

All qm files availabel to the **:/QtNativeTr/languages/** path.
For example:
* :/QtNativeTr/tr/assistant_cs.qm

If you want to add dynamic loading for qt translation you can user [QuasarAppLib::Locales](https://quasarapp.ddns.net:3031/docs/QuasarApp/QuasarAppLib/latest/classQuasarAppUtils_1_1Locales.html) class.

### Exmaple of use with QuasarAppLib::Locales

```cpp
#include <QtNativeTr.h>
#include <quasarapp.h

int main () {

    // init all included resources
    QtNativeTr::init();
    QuasarAppUtils::Locales::init(QLocale::system(), {":/QtNativeTr/languages/"});
    
    return 0;
}
```
