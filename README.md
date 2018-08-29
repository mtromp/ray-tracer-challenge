# ray-tracer-challenge
This project uses the book The Ray Tracer Challenge by Jamis Buck as the basis for this code.

## set up the workspace
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

