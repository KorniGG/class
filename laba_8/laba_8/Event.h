#pragma once

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;      // + 
const int cmDel = 2;      // -
const int cmGet = 3;      // z 
const int cmShow = 4;     // s
const int cmMake = 6;     // m
const int cmQuit = 101;   // q

struct TEvent {
	int what;
	int command;
};