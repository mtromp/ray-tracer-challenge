# ray-tracer-challenge
This project uses the book The Ray Tracer Challenge by Jamis Buck as the basis for this code.

## set up the workspace
After starting to set up my Mac with cucumber-cpp, I decided against it. The dependencies needed (e.g. Boost, Ruby and more) and my
familiarity with gtest/gmock, prompted me to get going with gtest/gmock. Maybe in the future I'll retry this project with Cucumber.
For now (20180901) I just want to get started with the project.

## CXX FLAGS
I needed to add `set (CMAKE_CXX_FLAGS "-std=c++1z")` so that the inclusion of algorithms would be for C++ 17. I wanted to use the clamp
function which is not available in the default std library.

## valgrind
I would like to use valgrind because I believe that I have some memory issues.
Since I have upgraded to Mac OS Mojave, valgrind will not build. My QTCreator needs
an external tool for memory checking.


## Old comments

*Pre-September 1, 2018*
This project will use Cucumber so that I can use the tests provided in the book. I plan to write the code using Qt Creator with C++ and the Qt Framework when appropriate.

### Ruby
I don't have ruby properly installed on my personal MacBook Pro. Will start by installing rbenv. Follow instructions from
https://github.com/rbenv/rbenv#homebrew-on-macos
```
brew install rbenv
rbenv init
## put a line at the end of .bash_profile
  eval "$(rbenv init -)"
```
I installed the XCode command line tools for my version of XCode by starting XCode and going to 
XCode | Open Developer Tool | More Developer Tools...
I had problems doing a simple `rbenv install 2.5.1` but I found that this version works:
```
RUBY_CONFIGURE_OPTS="--disable-dtrace" rbenv install -v 2.5.1
```
I only have access to the system ruby and cannot install gems because of permissions. Not Happy.
Went to the cucumber-cpp project that I had cloned. Added a .ruby-version file and placed "2.5.1" in it.

```
gem install bundler
bundle install
## aruba has a long message that I do not understand
```

