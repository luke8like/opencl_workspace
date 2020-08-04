#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <CL/cl.h>




void displayDeviceDetails(cl_device_id id,
	cl_device_info param_name,
	const char* paramNameAsStr) {
	cl_int error = 0;
	size_t paramSize = 0;

	error = clGetDeviceInfo(id, param_name, 0, NULL, &paramSize);
	if (error != CL_SUCCESS) {
		perror("Unable to obtain device info for param\n");
		return;
	}

	/* the cl_device_info are preprocessor directives defined in cl.h */
	switch (param_name) {
	case CL_DEVICE_TYPE: {
		cl_device_type* devType = (cl_device_type*)alloca(sizeof(cl_device_type) * paramSize);
		error = clGetDeviceInfo(id, param_name, paramSize, devType, NULL);
		if (error != CL_SUCCESS) {
			perror("Unable to obtain device info for param\n");
			return;
		}
		switch (*devType) {
		case CL_DEVICE_TYPE_CPU: printf("CPU detected\n"); break;
		case CL_DEVICE_TYPE_GPU: printf("GPU detected\n"); break;
		case CL_DEVICE_TYPE_ACCELERATOR: printf("Accelerator detected\n"); break;
		case CL_DEVICE_TYPE_DEFAULT: printf("default detected\n"); break;
		}
	}break;
	case CL_DEVICE_VENDOR_ID:
	case CL_DEVICE_MAX_COMPUTE_UNITS:
	case CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS: {
		cl_uint* ret = (cl_uint*)alloca(sizeof(cl_uint) * paramSize);
		error = clGetDeviceInfo(id, param_name, paramSize, ret, NULL);
		if (error != CL_SUCCESS) {
			perror("Unable to obtain device info for param\n");
			return;
		}
		switch (param_name) {
		case CL_DEVICE_VENDOR_ID: printf("\tVENDOR ID: 0x%x\n", *ret); break;
		case CL_DEVICE_MAX_COMPUTE_UNITS: printf("\tMaximum number of parallel compute units: %d\n", *ret); break;
		case CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS: printf("\tMaximum dimensions for global/local work-item IDs: %d\n", *ret); break;
		}
	}break;
	case CL_DEVICE_MAX_WORK_ITEM_SIZES: {
		cl_uint maxWIDimensions;
		size_t* ret = (size_t*)alloca(sizeof(size_t) * paramSize);
		error = clGetDeviceInfo(id, param_name, paramSize, ret, NULL);

		error = clGetDeviceInfo(id, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint), &maxWIDimensions, NULL);
		if (error != CL_SUCCESS) {
			perror("Unable to obtain device info for param\n");
			return;
		}
		printf("\tMaximum number of work-items in each dimension: ( ");
		for (cl_int i = 0; i < maxWIDimensions; ++i) {
			printf("%d ", ret[i]);
		}
		printf(" )\n");
	}break;
	case CL_DEVICE_MAX_WORK_GROUP_SIZE: {
		size_t* ret = (size_t*)alloca(sizeof(size_t) * paramSize);
		error = clGetDeviceInfo(id, param_name, paramSize, ret, NULL);
		if (error != CL_SUCCESS) {
			perror("Unable to obtain device info for param\n");
			return;
		}
		printf("\tMaximum number of work-items in a work-group: %d\n", *ret);
	}break;
	case CL_DEVICE_NAME:
	case CL_DEVICE_VENDOR: {
		char data[48];
		error = clGetDeviceInfo(id, param_name, paramSize, data, NULL);
		if (error != CL_SUCCESS) {
			perror("Unable to obtain device name/vendor info for param\n");
			return;
		}
		switch (param_name) {
		case CL_DEVICE_NAME: printf("\tDevice name is %s\n", data); break;
		case CL_DEVICE_VENDOR: printf("\tDevice vendor is %s\n", data); break;
		}
	} break;
	case CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE: {
		cl_uint* size = (cl_uint*)alloca(sizeof(cl_uint) * paramSize);
		error = clGetDeviceInfo(id, param_name, paramSize, size, NULL);
		if (error != CL_SUCCESS) {
			perror("Unable to obtain device name/vendor info for param\n");
			return;
		}
		printf("\tDevice global cacheline size: %d bytes\n", (*size)); break;
	} break;
	case CL_DEVICE_GLOBAL_MEM_SIZE:
	case CL_DEVICE_MAX_MEM_ALLOC_SIZE: {
		cl_ulong* size = (cl_ulong*)alloca(sizeof(cl_ulong) * paramSize);
		error = clGetDeviceInfo(id, param_name, paramSize, size, NULL);
		if (error != CL_SUCCESS) {
			perror("Unable to obtain device name/vendor info for param\n");
			return;
		}
		switch (param_name) {
		case CL_DEVICE_GLOBAL_MEM_SIZE: printf("\tDevice global mem: %ld mega-bytes\n", (*size) >> 20); break;
		case CL_DEVICE_MAX_MEM_ALLOC_SIZE: printf("\tDevice max memory allocation: %ld mega-bytes\n", (*size) >> 20); break;
		}
	} break;

	} //end of switch

}

void displayDeviceInfo(cl_platform_id id,
	cl_device_type dev_type) {
	/* OpenCL 1.1 device types */
	cl_int error = 0;
	cl_uint numOfDevices = 0;

	/* Determine how many devices are connected to your platform */
	error = clGetDeviceIDs(id, dev_type, 0, NULL, &numOfDevices);
	if (error != CL_SUCCESS) {
		perror("Unable to obtain any OpenCL compliant device info");
		exit(1);
	}
	cl_device_id* devices = (cl_device_id*)alloca(sizeof(cl_device_id) * numOfDevices);

	/* Load the information about your devices into the variable 'devices' */
	error = clGetDeviceIDs(id, dev_type, numOfDevices, devices, NULL);
	if (error != CL_SUCCESS) {
		perror("Unable to obtain any OpenCL compliant device info");
		exit(1);
	}
	printf("Number of detected OpenCL devices: %d\n", numOfDevices);
	/* We attempt to retrieve some information about the devices. */
	for (int i = 0; i < numOfDevices; ++i) {
		displayDeviceDetails(devices[i], CL_DEVICE_TYPE, "CL_DEVICE_TYPE");
		displayDeviceDetails(devices[i], CL_DEVICE_NAME, "CL_DEVICE_NAME");
		displayDeviceDetails(devices[i], CL_DEVICE_VENDOR, "CL_DEVICE_VENDOR");
		displayDeviceDetails(devices[i], CL_DEVICE_VENDOR_ID, "CL_DEVICE_VENDOR_ID");
		displayDeviceDetails(devices[i], CL_DEVICE_MAX_MEM_ALLOC_SIZE, "CL_DEVICE_MAX_MEM_ALLOC_SIZE");
		displayDeviceDetails(devices[i], CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, "CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE");
		displayDeviceDetails(devices[i], CL_DEVICE_GLOBAL_MEM_SIZE, "CL_DEVICE_GLOBAL_MEM_SIZE");
		displayDeviceDetails(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, "CL_DEVICE_MAX_COMPUTE_UNITS");
		displayDeviceDetails(devices[i], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, "CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS");
		displayDeviceDetails(devices[i], CL_DEVICE_MAX_WORK_ITEM_SIZES, "CL_DEVICE_MAX_WORK_ITEM_SIZES");
		displayDeviceDetails(devices[i], CL_DEVICE_MAX_WORK_GROUP_SIZE, "CL_DEVICE_MAX_WORK_GROUP_SIZE");
	}
}

const int ARRAY_SIZE = 1000;
/*
1. 创建平台
2. 创建设备
3. 根据设备创建上下文
*/
cl_context CreateContext(cl_device_id* device) {
	cl_int errNum;
	cl_uint numPlateforms;
	cl_platform_id  *platformIds;
	cl_platform_id firstPlatformId;
	cl_context context = NULL;

	errNum = clGetPlatformIDs(0, NULL, &numPlateforms);
	printf("number of platform: %d\n", numPlateforms);
	platformIds = (cl_platform_id*)alloca(sizeof(cl_platform_id) * numPlateforms);


	//errNum = clGetPlatformIDs(1, platformIds, &numPlateforms);
	errNum = clGetPlatformIDs(numPlateforms, platformIds, NULL);
	firstPlatformId = platformIds[1];

	{
		displayDeviceInfo(platformIds[0], CL_DEVICE_TYPE_ALL);
		displayDeviceInfo(platformIds[1], CL_DEVICE_TYPE_ALL);
	}

	if (errNum != CL_SUCCESS || numPlateforms <= 0) {
		printf("Failed to find any OpenCL platforms.\n");
		return NULL;
	}
	errNum = clGetDeviceIDs(firstPlatformId, CL_DEVICE_TYPE_GPU, 1, device, NULL);
	if (errNum != CL_SUCCESS) {
		printf("There is no GPU , trying CPU...\n");
		errNum = clGetDeviceIDs(firstPlatformId, CL_DEVICE_TYPE_CPU, 1, device, NULL);

	}
	 
	if (errNum != CL_SUCCESS) {
		printf("There is NO CPU or GPU\n");
		return NULL;
	}


	context = clCreateContext(NULL, 1, device, NULL, NULL, &errNum);
	if (errNum != CL_SUCCESS) {
		printf("Create context error\n");
		return NULL;
	}
	return context;
}
/*
@ 在上下文可用的第一个设备中创建命令队列
*/

cl_command_queue CreateCommandQueue(cl_context context, cl_device_id device) {
	cl_int errNum;
	cl_command_queue commandQueue = NULL;
	//commandQueue = clCreateCommandQueue(context, device, 0, NULL);
	// OpenCL 2.0 的用法
	commandQueue = clCreateCommandQueueWithProperties(context, device, 0, NULL);
	if (commandQueue == NULL) {
		printf("Failed to create commandQueue for device 0\n");
		return NULL;
	}
	return commandQueue;
}

char* ReadKernelSourceFile(const char* filename, size_t* length) {
	FILE* file = NULL;
	size_t sourceLenth;
	char* sourceString;
	int ret;
	file = fopen(filename, "rb");
	if (file == NULL) {
		printf("%s at %d : Can't open %s \n", __FILE__, __LINE__ - 2, filename);
		return NULL;
	}
	//重定位到文件末尾
	fseek(file, 0, SEEK_END);
	sourceLenth = ftell(file);
	//重定位到文件开头
	fseek(file, 0, SEEK_SET);
	sourceString = (char*)malloc(sourceLenth + 1);
	sourceString[0] = '\0';
	ret = fread(sourceString, sourceLenth, 1, file);
	if (ret == 0) {
		printf("%s at %d : Cant't read source %s\n", __FILE__, __LINE__ - 2, filename);
		return NULL;
	}
	fclose(file);
	if (length != 0) {
		*length = sourceLenth;
	}
	sourceString[sourceLenth] = '\0';
	return sourceString;


}
cl_program CreateProgram(cl_context context, cl_device_id device, const char* filename) {
	cl_int errNum;
	cl_program program;
	//记录大小的数据类型
	size_t program_length;
	char* const source = ReadKernelSourceFile(filename, &program_length);
	program = clCreateProgramWithSource(context, 1, (const char**)& source, NULL, NULL);

	if (program == NULL) {
		printf("Failed to creae CL program from source.\n");
		return NULL;
	}
	errNum = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (errNum != CL_SUCCESS) {
		char buildLog[16384];
		clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, sizeof(buildLog), buildLog, NULL);
		printf("Error in kernel : %s \n", buildLog);
		clReleaseProgram(program);
		return NULL;
	}
	return program;
}
/*
@ 创建内存对象
*/
bool  CreateMemObjects(cl_context context, cl_mem memObjects[3], float* a, float* b) {
	memObjects[0] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * ARRAY_SIZE, a, NULL);
	memObjects[1] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * ARRAY_SIZE, b, NULL);
	memObjects[2] = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(float) * ARRAY_SIZE, NULL, NULL);
	if (memObjects[0] == NULL || memObjects[1] == NULL || memObjects[2] == NULL) {
		printf("Error creating memeory objects.\n");
		return false;

	}
	return true;
}
/*
@ 清楚OpenCL资源
*/
void CleanUp(cl_context context, cl_command_queue commandQueue, cl_program program, cl_kernel kernel, cl_mem memObjects[3]) {
	for (int i = 0; i < 3; i++) {
		if (memObjects[i] != 0) {
			clReleaseMemObject(memObjects[i]);
		}
	}

	if (commandQueue != 0) {
		clReleaseCommandQueue(commandQueue);
	}
	if (kernel != 0) {
		clReleaseKernel(kernel);
	}
	if (program != 0) {
		clReleaseProgram(program);
	}
	if (context != 0) {
		clReleaseContext(context);
	}
}

/*main函数*/
int main(int argc, char** agrv) {
	cl_context context = 0;
	cl_command_queue commandQueue = 0;
	cl_program program = 0;
	cl_device_id device = 0;
	cl_kernel kernel = 0;
	cl_mem memObjects[3] = { 0,0,0 };
	cl_int errNum;
	//创建OpenCL上下文
	context = CreateContext(&device);
	if (context == NULL) {
		printf("Failed to create OpenCL context\n");
		return 1;
	}
	//获得OpenCL设备，并创建命令队列
	commandQueue = CreateCommandQueue(context, device);
	if (commandQueue == NULL) {
		CleanUp(context, commandQueue, program, kernel, memObjects);
		return 1;
	}
	//创建OpenCL程序
	program = CreateProgram(context, device, "vecAdd.cl");
	if (program == NULL) {
		CleanUp(context, commandQueue, program, kernel, memObjects);
		return 1;
	}
	kernel = clCreateKernel(program, "vector_add", NULL);
	if (kernel == NULL) {
		printf("Failed to create kernel\n");
		CleanUp(context, commandQueue, program, kernel, memObjects);
		return 1;

	}
	//创建OpenCL内存对象
	float result[ARRAY_SIZE];
	float a[ARRAY_SIZE];
	float b[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		a[i] = (float)i;
		b[i] = (float)(i * 2);
	}
	if (!CreateMemObjects(context, memObjects, a, b)) {
		CleanUp(context, commandQueue, program, kernel, memObjects);
		return 1;
	}
	//设置内核参数
	errNum = clSetKernelArg(kernel, 0, sizeof(cl_mem), &memObjects[0]);
	errNum |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &memObjects[1]);
	errNum |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &memObjects[2]);

	if (errNum != CL_SUCCESS) {
		printf("Error setting kernel arguments.\n");
		CleanUp(context, commandQueue, program, kernel, memObjects);
		return 1;
	}
	size_t globalWorkSize[1] = { ARRAY_SIZE };
	size_t localWorkSize[1] = { 1 };
	//执行内核
	errNum = clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL);
	if (errNum != CL_SUCCESS) {
		printf("Error queueing kernel for execution\n");
		CleanUp(context, commandQueue, program, kernel, memObjects);
		return 1;
	}
	//将计算的结果拷贝到主机上
	errNum = clEnqueueReadBuffer(commandQueue, memObjects[2], CL_TRUE, 0, ARRAY_SIZE * sizeof(float), result, 0, NULL, NULL);
	if (errNum != CL_SUCCESS) {
		printf("Error reading result buffer.\n");
		CleanUp(context, commandQueue, program, kernel, memObjects);
		return 1;
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("i=%d:%f\n", i, result[i]);
	}
	printf("Executed program succesfully\n");
	CleanUp(context, commandQueue, program, kernel, memObjects);
	return 0;
}