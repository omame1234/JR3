﻿#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char buf[128];

struct student {
	int id;
	char name[32];
	int score;
};

typedef struct student datatype;

struct node {
	datatype data;
	struct node *left;
	struct node *right;
};

void print_tree(struct node *t)
{
	//うめる
	if (t == NULL) {
		printf("-");
	} else {
		printf("%d(", t->data.id);
		print_tree(t->left);
		printf(",");
		print_tree(t->right);
		printf(")");
	}
}

struct node *get_tree()
{
	struct node *t;
	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
		return NULL;
	} else {
		t = (struct node *)malloc(sizeof(struct node));
		sscanf(buf, "%d,%[^,],%d", &t->data.id, t->data.name,
		       &t->data.score);
		t->left = get_tree();
		t->right = get_tree();
		return t;
	}
}

struct node *bst_insert(struct node *t, struct student d)
{
	struct node *temp;
	struct node *node;
	//nodeのアドレスtの指す接点を根とする二分探索木に、構造体studentの値dをメンバdataとする接点を追加
	node = t;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	while(true){
		if (node == NULL) {
			t = temp;
			return t;
		}
		if(node->data.id < d.id){
			if(node->right != NULL){
				node = node->right;
			}
			else {
				node->right = temp;
				return t;
			}
		}else{
			if (node->left != NULL) {
				node = node->left;
			}
			else {
				node->left = temp;
				return t;
			}
		}
	}
	//得られた二分探索木の根の接点のアドレスを返す
}

void print_bst(struct node *t)
{
	if (t == NULL) {
		printf(".\n");
	} else {
		printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
		print_bst(t->left);
		print_bst(t->right);
	}
}

int main()
{
	struct node *t = get_tree();
	struct student d;
	scanf("%d,%[^,],%d ", &d.id, d.name, &d.score);
	t = bst_insert(t, d);
	print_bst(t);
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
