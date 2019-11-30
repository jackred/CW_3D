#version 130

attribute vec4 position;
                //note: "attribute" should be changed to "in" on versions 130 and above

  void main(){
    gl_Position = position;
  }
