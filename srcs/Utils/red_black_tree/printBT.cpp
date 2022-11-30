
void printBT(const std::string& prefix, const BSTNode* node, bool isLeft)
{
	if( node != nullptr )
	{
		std::cout << prefix;

		std::cout << (isLeft ? "├──" : "└──" );

		// print the value of the node
		std::cout << node->m_val << std::endl;

		// enter the next tree level - left and right branch
		printBT( prefix + (isLeft ? "│   " : "    "), node->m_left, true);
		printBT( prefix + (isLeft ? "│   " : "    "), node->m_right, false);
	}
}

void printBT(const BSTNode* node)
{
	printBT("", node, false);
}

// pass the root node of your binary tree
printBT(root);