#ifndef __OPCODE_HPP__
#define __OPCODE_HPP__



namespace fas {
enum class OpCode {
	// ջ����
	PUSH_NULL,		// ѹ��һ����ֵ
	PUSH_BOOL,		// ѹ��һ�� bool ����ֵ�����1�ֽھ���ֵ
	PUSH_INT64,		// ѹ��һ�� int64 ����ֵ�����8�ֽھ���ֵ
	PUSH_FLOAT64,	// ѹ��һ�� double ����ֵ�����8�ֽھ���ֵ
	PUSH_GLOBAL,	// ѹ��һ��ȫ�ֱ���ֵ�����2�ֽ�ID
	PUSH_MEMBER,	// ѹ��һ�����Ա����ֵ�����2�ֽ�ID
	PUSH_ARGUMENT,	// ѹ��һ������ֵ
	PUSH_VARIABLE,	// ѹ��һ���ֲ�����ֵ
	POP_GLOBAL,		// ����һ��ֵ��ȫ�ֱ���
	POP_MEMBER,		// ����һ��ֵ�������Ա����
	POP_ARGUMENT,	// ����һ��ֵ������
	POP_VARIABLE,	// ����һ��ֵ���ֲ�����
	POP,			// ����һ��ֵ�����ԣ�

	// ����
	NOT,			// ȡ�� ��1->1��
	AND,			// �����㣨2->1��
	OR,				// �����㣨2->1��

	// ��������
	INVOKE,			// ѹ�뵱ǰִ��λ�ã�4�ֽڣ������ú�����˳�򣺴������ҽ�����ѹջ��Ȼ��ѹ����ID�����INVOKE��
	RET,			// �������أ��ָ��ֳ�

	OPCODE_END,		// ���һ�������������ھ�̬У����������Ȳ���255
};

static_assert ((int) OpCode::OPCODE_END <= 256, "�������������ܳ�256");
}



#endif //__OPCODE_HPP__
