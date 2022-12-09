// bytecodeVisitor
#include "backend/include/instruction.hh"
#include "frontend/include/expr.hh"

/* THE MAIN PROBLEM THAT I AM FACING */
/*
    Sometimes an instruction should not get executed and instead an error should be returned
    We need a way to 

*/


namespace Essembly
{
    

// BytecodeVisitor
}
// BytecodeVisitor
    for(size_t i = 0; i < instructions.size(); i++) {
        if (instructions[i]) {
            delete instructions[i];
            instructions[i] = nullptr;
        }
    }
}

// BytecodeVisitor
    Expr* lhs = expr->lhs.get();
    Expr* rhs = expr->rhs.get();
// BytecodeVisitor
// BytecodeVisitor
}

// BytecodeVisitor
    return binaryExprHelper(expr);
}

// BytecodeVisitor
    return visitBinaryExpr(expr); 
}

// BytecodeVisitor
    return visitBinaryExpr(expr); 
}

// BytecodeVisitor
    return visitBinaryExpr(expr); 
}

// BytecodeVisitor
    return visitBinaryExpr(expr); 
}

// BytecodeVisitor
    binaryExprHelper(expr);
    /* add the add instruction at the end */
    instructions.push_back(new IADD_i());
}
// BytecodeVisitor
    binaryExprHelper(expr);
    /* add the sub instruction at the end */
    instructions.push_back(new ISUB_i());
}

// BytecodeVisitor
    binaryExprHelper(expr);
    /* add the sub instruction at the end */
    instructions.push_back(new IMUL_i());
}

// BytecodeVisitor
    binaryExprHelper(expr);
    /* add the sub instruction at the end */
    instructions.push_back(new IDIV_i());
}

// BytecodeVisitor
}

// BytecodeVisitor
    /* first we need to check for compatibility */
    /* can we not every value? */
    /* I do not think that having truthy or falsy values is a good idea */
    /* so I will enforce that the type of the expression must be bool */
}

// BytecodeVisitor

}


/* TODO: implement bytecode generator for unary expressions */
static inline Instruction* chooseFinalBinaryInstruction(TT type) {
    switch (type)
    {
    case TT::PLUS:
        return new IADD_i();

    case TT::MINUS:
        return new ISUB_i();

    case TT::SLASH:
        return new IDIV_i();

    case TT::TIMES:
        return new IMUL_i();

    default:
        break;
    }
}

// TODO: #5 add support for unary expression @Alex-AandD
static inline Instruction* chooseFinalUnaryExpr(TT type) {
}

// BytecodeVisitor
    /* here we push an integer onto the stack */
    /* the value of the expression is going to be the operand */
    /* so the instruction at the end is going to look like this */
    /* IPUSH operand */
    instructions.push_back(new IPUSH_i(expr->value));
}

} // Essembly