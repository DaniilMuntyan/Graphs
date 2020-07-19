#pragma once
#ifndef H_GRAPHCONVERT
#define H_GRAPHCONVERT
#include "SetGraph.h"
#include "SetGraphAlgs.h"
#include "ListGraph.h"
#include "ListGraphAlgs.h"
#include "MatrixGraph.h"
#include "MatrixGraphAlgs.h"
#include <set>
#include <list>
class GraphConvert {
public:
	SetGraph* ConvertToSet(const MatrixGraph &srcGraph);
	SetGraph* ConvertToSet(const ListGraph &srcGraph);
	MatrixGraph* ConvertToMatrix(const ListGraph &srcGraph);
	MatrixGraph* ConvertToMatrix(const SetGraph & srcGraph);
	ListGraph* ConvertToList(const SetGraph &srcGraph);
	ListGraph* ConvertToList(const MatrixGraph &srcGraph);
};
#endif