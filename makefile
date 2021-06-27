APPLICATION_NAME=visutech_test_app

build:
	docker build -t $(APPLICATION_NAME) .

run:
	docker run --rm -v $(dir $(src)):/src_file/ -v $(dir $(dest)):/dest_file/ \
		$(APPLICATION_NAME) \
		--src=/src_file/$(notdir $(src)) \
		--word=$(word) \
		--dest=/dest_file/$(notdir $(dest))
