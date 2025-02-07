#pragma once
//ブロックのサイズ
const int BlockSize =  32;

//ブロックの数
//Ver...「Vertical」の略
const int  VerBlockNum = 25;
//Hol...「Holizontal」の略
const int HolBlockNum = 50;

//ワールドサイズ
const int WorldHeight = BlockSize * VerBlockNum;
const int WorldWidth = BlockSize * HolBlockNum;

//==============================
//     ウィンドウサイズ
//==============================
const int WindowHeight = 720;
const int WindowWidth = 1280;
